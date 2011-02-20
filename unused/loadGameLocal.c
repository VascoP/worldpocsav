char *loadGameLocal(void)
{
	DIR * dir;
	struct dirent * file;
	char *files[256]; /*using max 256 because its readdir max output name*/
	int option, i = 0;

	/*try to open the saves directory*/
	if((dir = opendir("saves")) != NULL)
	{
		/*reads and stores present files*/		
		for(i = 0; (file = readdir(dir)); i++)
		{
			/*filter empty names*/
			if(file->d_name[0] != '.')
			{
				files[i] = malloc((strlen(file->d_name)+1)*sizeof(char));
				files[i] = file->d_name;
			}
			else
				i--;
		}

		closedir(dir);	
  	}
	/*menu with different files*/
	option = createMenu("Saved Games", files, i, MARGIN, 0, 1);

	if(option == i)
		return NULL;
	else
		return files[option];
}
