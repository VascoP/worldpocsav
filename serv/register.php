<?php 

$usersFile = "users";
$newfile = "sync/" . $_POST["name"] . ".php";

$fp = fopen($usersFile, 'a+');

while (($readLine = fgets($fp)) != false) {
	$name = strtok($readLine, "__::__");
	
	if($name == $_POST["name"])
	{
        echo "dup";
		exit(0);
	}
}

echo "Ok";

$userInfo = $_POST["name"]."__::__".$_POST["pass"]."\n";

fwrite($fp, $userInfo);
fclose($fp); 

copy("sync.php", $newfile);
chmod($newfile, 0777); 

?>
		
