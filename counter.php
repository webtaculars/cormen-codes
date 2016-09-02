<?php

$filename = 'hitcount.txt';
$handle = fopen($filename, 'r');
$hits = trim(fgets($handle)) + 1;
fclose($handle);

$handle = fopen($filename, 'w');
fwrite($handle, $hits);
fclose($handle);

// Uncomment the next line (remove //) to display the number of hits on your page.
echo $hits;

?>

