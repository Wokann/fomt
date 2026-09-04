[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)]
    [ValidateNotNullOrEmpty()]
    [string]$MaryCharmap
)

$ErrorActionPreference = 'Stop'

$scriptDirectory = Split-Path -Parent $PSCommandPath
$repositoryRoot = (Resolve-Path (Join-Path $scriptDirectory '..\..\..')).Path
$sourcePath = (Resolve-Path -LiteralPath $MaryCharmap).Path
$acceptedNames = @('charmap.txt', 'charmap_jp.txt')

if ((Split-Path -Leaf $sourcePath) -notin $acceptedNames) {
    throw "Expected a reviewed charmap named '$($acceptedNames -join "' or '")', got '$sourcePath'."
}

$destinationPath = Join-Path $repositoryRoot 'charmap.txt'
$legacyPaths = @(
    (Join-Path $repositoryRoot 'charmap_jp.txt'),
    (Join-Path $repositoryRoot 'data\text\charmap_jp.txt')
)
$destinationDirectory = Split-Path -Parent $destinationPath
New-Item -ItemType Directory -Force -Path $destinationDirectory | Out-Null

$sourceHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $sourcePath).Hash
if (Test-Path -LiteralPath $destinationPath) {
    $existingHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $destinationPath).Hash
    if ($existingHash -ne $sourceHash) {
        throw "Refusing to overwrite a different project charmap at '$destinationPath'."
    }
} else {
    Copy-Item -LiteralPath $sourcePath -Destination $destinationPath
}
$destinationHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $destinationPath).Hash

if ($sourceHash -ne $destinationHash) {
    throw "Checksum mismatch after importing '$sourcePath'."
}

foreach ($legacyPath in $legacyPaths) {
    if (Test-Path -LiteralPath $legacyPath) {
        $legacyHash = (Get-FileHash -Algorithm SHA256 -LiteralPath $legacyPath).Hash
        if ($legacyHash -ne $sourceHash) {
            throw "Refusing to remove a different legacy charmap at '$legacyPath'."
        }
        Remove-Item -LiteralPath $legacyPath -Force
    }
}

Write-Output "Imported charmap.txt with SHA-256 $destinationHash"
