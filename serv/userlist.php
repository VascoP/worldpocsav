<?php

$usersFile = "users";

if(!file_exists($usersFile))
{
	echo "<h1>No users registered!</h1>";
	exit(0);
}

$fp = fopen($usersFile, 'r');

echo "<h1>Registered Users</h1>";

while (($readLine = fgets($fp)) != false) 
{
  $name = strtok($readLine, "__::__");
  echo "<p><a href=\"profiles/$name.php\">".$name."</a></p>";
}

fclose($fp); 

?>
