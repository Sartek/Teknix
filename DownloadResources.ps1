function Get-Script-Directory
{
    $scriptInvocation = (Get-Variable MyInvocation -Scope 1).Value
    return Split-Path $scriptInvocation.MyCommand.Path
}

function Extract-Zip
{
    param([string]$zipfilename, [string] $destination)

    if(test-path($zipfilename))
    { 
        $shellApplication = new-object -com shell.application
        $zipPackage = $shellApplication.NameSpace($zipfilename)
        $destinationFolder = $shellApplication.NameSpace($destination)
        $destinationFolder.CopyHere($zipPackage.Items())
    }
}

$index = "https://dl.dropbox.com/u/95785669/Teknix"
$path = Get-Script-Directory

if(Test-Path -PathType Container "$path\packages")
{
}
else
{
    mkdir -path "$path\packages" >$null
}
$client = new-object System.Net.WebClient
echo "Getting Resource Version"
$client.DownloadFile( "$index/version-res", "$path\packages\version-res" )
$versionres = Get-Content "$path\packages\version-res"
echo "Resource Version is $versionres"
if(Test-Path -PathType Leaf "$path\packages\res-$versionres.zip")
{
    echo "Latest Version of Resources already downloaded"
}
else
{
    echo "Downloading Latest Resources"
    $client.DownloadFile( "$index/res-$versionres.zip", "$path\packages\res-$versionres.zip" )
}
$path = Get-Script-Directory
echo "Extracting res-$versionres.zip"
Extract-Zip "$path\packages\res-$versionres.zip" "$path"
echo "Finished Successfully"