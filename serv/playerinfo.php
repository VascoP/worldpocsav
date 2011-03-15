<?php 

$usersFile = "users";

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
			echo "Ok";
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
