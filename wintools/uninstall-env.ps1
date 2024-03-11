$toolsPath = "$PSScriptRoot/tools"
$clangDirectoryName = "clang+llvm-18.1.1-x86_64-pc-windows-msvc"
$cmakeDirectoryName = "cmake-3.28.3-windows-x86_64"

Write-Output "Removing Clang, Ninja, and CMake from PATH..."
$currDirs = (Get-Item -LiteralPath "registry::HKEY_CURRENT_USER\Environment").GetValue('Path', '', 'DoNotExpandEnvironmentNames') -split ';' -ne ''
$newDirs = Where-Object -InputObject $currDirs { (Resolve-Path $_) -ne (Resolve-Path "$toolsPath") -and (Resolve-Path $_) -ne (Resolve-Path "$toolsPath/$clangDirectoryName/bin") -and (Resolve-Path $_) -ne (Resolve-Path "$toolsPath/$cmakeDirectoryName/bin") }
$newValue = $newDirs -join ';'
Set-ItemProperty -Type ExpandString -LiteralPath "registry::HKEY_CURRENT_USER\Environment" Path $newValue

Write-Output "Deleting Clang, Ninja, and CMake..."
Remove-Item -Recurse -Force "$toolsPath"