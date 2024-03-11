$clangUrl = "https://github.com/llvm/llvm-project/releases/download/llvmorg-18.1.1/clang+llvm-18.1.1-x86_64-pc-windows-msvc.tar.xz"
$clangArchiveName = "clang+llvm-18.1.1-x86_64-pc-windows-msvc.tar.xz"
$clangDirectoryName = "clang+llvm-18.1.1-x86_64-pc-windows-msvc"
$ninjaUrl = "https://github.com/ninja-build/ninja/releases/download/v1.11.1/ninja-win.zip"
$ninjaArchiveName = "ninja-win.zip"
$cmakeUrl = "https://github.com/Kitware/CMake/releases/download/v3.28.3/cmake-3.28.3-windows-x86_64.zip"
$cmakeArchiveName = "cmake-3.28.3-windows-x86_64.zip"
$cmakeDirectoryName = "cmake-3.28.3-windows-x86_64"
$toolsPath = "$PSScriptRoot/tools"

# https://stackoverflow.com/a/69239861
function Add-Path {
    param(
        [Parameter(Mandatory, Position=0)]
        [string] $LiteralPath,
        [ValidateSet('User', 'CurrentUser', 'Machine', 'LocalMachine')]
        [string] $Scope 
    )

    Set-StrictMode -Version 1; $ErrorActionPreference = 'Stop'

    $isMachineLevel = $Scope -in 'Machine', 'LocalMachine'
    if ($isMachineLevel -and -not $($ErrorActionPreference = 'Continue'; net session 2>$null)) { throw "You must run AS ADMIN to update the machine-level Path environment variable." }  

    $regPath = 'registry::' + ('HKEY_CURRENT_USER\Environment', 'HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment')[$isMachineLevel]

    # Note the use of the .GetValue() method to ensure that the *unexpanded* value is returned.
    $currDirs = (Get-Item -LiteralPath $regPath).GetValue('Path', '', 'DoNotExpandEnvironmentNames') -split ';' -ne ''

    if ($LiteralPath -in $currDirs) {
        Write-Verbose "Already present in the persistent $(('user', 'machine')[$isMachineLevel])-level Path: $LiteralPath"
        return
    }

    $newValue = ($currDirs + $LiteralPath) -join ';'

    # Update the registry.
    Set-ItemProperty -Type ExpandString -LiteralPath $regPath Path $newValue

    # Broadcast WM_SETTINGCHANGE to get the Windows shell to reload the
    # updated environment, via a dummy [Environment]::SetEnvironmentVariable() operation.
    $dummyName = [guid]::NewGuid().ToString()
    [Environment]::SetEnvironmentVariable($dummyName, 'foo', 'User')
    [Environment]::SetEnvironmentVariable($dummyName, [NullString]::value, 'User')

    # Finally, also update the current session's `$env:Path` definition.
    # Note: For simplicity, we always append to the in-process *composite* value,
    #        even though for a -Scope Machine update this isn't strictly the same.
    $env:Path = ($env:Path -replace ';$') + ';' + $LiteralPath

    Write-Verbose "`"$LiteralPath`" successfully appended to the persistent $(('user', 'machine')[$isMachineLevel])-level Path and also the current-process value."

}

if(!(Test-Path $toolsPath))
{
    New-Item -ItemType Directory -Path $toolsPath
}

Write-Output "Downloading Clang..."
Invoke-WebRequest $clangUrl -OutFile "$toolsPath/$clangArchiveName"
Write-Output "Extracting Clang..."
$prevCwd = Get-Location
Set-Location $toolsPath
tar -xf "$clangArchiveName"
Set-Location $prevCwd
Write-Output "Removing Clang archive..."
Remove-Item -Force "$toolsPath/$clangArchiveName"
Write-Output "Adding Clang to PATH..."
Add-Path "$toolsPath/$clangDirectoryName/bin"

Write-Output "Downloading Ninja..."
Invoke-WebRequest $ninjaUrl -OutFile "$toolsPath/$ninjaArchiveName"
Write-Output "Extracting Ninja..."
Expand-Archive "$toolsPath/$ninjaArchiveName" $toolsPath
Write-Output "Removing Ninja Archive..."
Remove-Item -Force "$toolsPath/$ninjaArchiveName"
Write-Output "Adding Ninja to PATH..."
Add-Path $toolsPath

Write-Output "Downloading CMake..."
Invoke-WebRequest $cmakeUrl -OutFile "$toolsPath/$cmakeArchiveName"
Write-Output "Extracting CMake..."
Expand-Archive "$toolsPath/$cmakeArchiveName" $toolsPath
Write-Output "Removing CMake Archive..."
Remove-Item -Force "$toolsPath/$cmakeArchiveName"
Write-Output "Adding CMake to PATH..."
Add-Path "$toolsPath/$cmakeDirectoryName/bin"

Write-Output ""
Write-Output "================"
Write-Output "* You can see these instructions again at any time by looking at the bottom of 'wintools/install.ps1' *"
Write-Output "1. Close and reopen VSCode"
Write-Output "3. Install the VSCode CMake extensions, if you don't already have it"
Write-Output "4. Press Ctrl+P, search 'kit', and run 'CMake: Scan for Kits'"
Write-Output "5. Press Ctrl+P, search 'kit', and run 'CMake: Select Kit' - Select Clang"
Write-Output "6. Go to VSCode's CMake tab, hover over 'Project Outline', and press the first icon ('Configure All Projects')"
Write-Output "7. In VSCode's CMake tab, hover over 'Pinned Commands', and press the plus - Select 'Debug'"
Write-Output "8. In the 'Pinned Commands' section, hover over 'Debug' and press the run icon"