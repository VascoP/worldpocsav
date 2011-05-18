<?php 

$usersFile = "users";
$syncfile = "sync/" . $_POST["name"] . ".php";
$statusfile = "status/" . $_POST["name"] . ".php";


$fp = fopen($usersFile, 'a+');

while (($readLine = fgets($fp)) != false) {
	$name = strtok($readLine, "__::__");
	
	if($name == $_POST["name"])
	{
        echo "dup";
		exit(0);
	}
}

$userInfo = $_POST["name"]."__::__".$_POST["pass"]."\n";

fwrite($fp, $userInfo);
fclose($fp); 

copy("sync.php", $syncfile);
chmod($syncfile, 0777); 

echo "ok";
exit(0);
?>
		
