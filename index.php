<?php
/**
* Function echos all files in a $directory.
**/

function dirList ($directory) {

    $dir = opendir($directory);
    while ($file = readdir($dir )) {
        echo "<div><a href='$file'>$file</a></div>";
    }
    closedir($dir);
    return $results;
}
?>
<html>
<head>
<title>
Created by praveen [praveen.91@samsung.com]
</title>
</head>
<?php
// Othewise, use the current file's directory as a seed.
dirList( dirname( __FILE__ ) );
?>
</html>