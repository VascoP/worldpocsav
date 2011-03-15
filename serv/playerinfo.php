<?php 

$usersFile = "users";
$status = "status/" . $_POST["name"];

if(!file_exists($usersFile))
{
	echo "NotFound";
	exit(0);
}

$fp = fopen($usersFile, 'r');

while (($readLine = fgets($fp)) != false) 
{
	$chunks = explode("__::__", $readLine);
	
	if($chunks[0] == $_POST["name"])
	{       
        $pass = $_POST["pass"]."\n";
		if(strcmp($chunks[1], $pass) == 0)
		{
			fclose($fp);
			$fp = fopen($status, "r");
			$readLine = fgets($fp);
			echo "$readLine";
			fclose($fp);
			exit(0);
		}
		else
		{
			echo "WrongPass";
            fclose($fp); 
			exit(0);
		}
	}
}
echo "NotFound";
fclose($fp); 
exit(0);
?>											
