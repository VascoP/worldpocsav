<?php 

$Name = $_POST["name"];

$Gold = $_POST["Gold"]; 
$HP = $_POST["HP"]; 
$Speed = $_POST["Speed"]; 
$Wisdom = $_POST["Wisdom"]; 
$Agility = $_POST["Agility"]; 
$Strenght = $_POST["Strenght"]; 
$Resistance = $_POST["Resistance"]; 

$path = "../profiles/" . $Name . ".php";

$fp = fopen($path, 'w');

fwrite($fp, "<h1>$Name</h1>");
fwrite($fp, "<p>HP: $HP</p>");
fwrite($fp, "<p>Speed: $Speed</p>");
fwrite($fp, "<p>Wisdom: $Wisdom</p>");
fwrite($fp, "<p>Agility: $Agility</p>");
fwrite($fp, "<p>Strenght: $Strenght</p>");
fwrite($fp, "<p>Resistance: $Resistance</p>");

fclose($fp);

$path = "../status/" . $Name;

$fp = fopen($path, 'w');

fwrite($fp, "$HP $Speed $Wisdom $Agility $Strenght $Resistance");

fclose($fp);

echo $Name;

?>
