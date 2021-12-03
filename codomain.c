void codomain (char *str)
{
    printf("[DEBUG] -- codomain --\n");
    int string_length = strlen(str);
    printf ("[DEBUG]strlen=%d\n", string_length);
    char *completed_string = malloc(sizeof(char));
    if (completed_string == NULL)
    {
        fprintf(stderr,"[ERROR] Memory Allocation Problem\n");
        exit(EXIT_FAILURE);           
    }

    for (int i = 2;i < string_length; i++) //Starts with 2 to ignore 'C '
    {
        if (str[i] == '(')
        {
            
            for (i = i; str[i] != ' '; i++){}
            i++;
            char *string_found = malloc(sizeof(char));
            if (string_found == NULL)
            {
                fprintf(stderr,"[ERROR] Memory Allocation Problem\n");
                free(completed_string);
                free(string_found);
                exit(EXIT_FAILURE);           
            }
            int new_string_len = 2;
            printf ("[DEBUG]i=%d\n", i);

            for (i = i; str[i] != ')'; i++) //Founds declared string
            {
                char *new_string = realloc(string_found,new_string_len*sizeof(char));
                if (new_string == NULL)
                {
                    fprintf(stderr,"[ERROR] Memory Reallocation Problem\n");
                    free(completed_string);
                    free(string_found);
                    exit(EXIT_FAILURE);
                }
                new_string[new_string_len-2] = str[i];
                new_string[new_string_len-1] = '\0';
                new_string_len++;
                string_found = new_string;
            }
            printf ("[DEBUG]string_found = %s\n", string_found);
            int string_found_length = strlen(string_found);
            int completed_string_length = strlen(completed_string);
            printf("[DEBUG]cmpstring=%d\n", completed_string_length);

            if (completed_string_length > 0)
            {
                char *new_string = malloc((string_found_length+3)*sizeof(char));
                new_string[0] = ' ';
                for (int j = 1; j <= string_found_length+2;j++)
                {
                    new_string[j] = string_found[j-1];
                }
                new_string[string_found_length+1] = ' ';
                new_string[string_found_length+1] = '\0';
                
                if (strstr(completed_string,new_string) == NULL)
                {
                    int max_length = completed_string_length+string_found_length;
                    char *new_completed_string = realloc(completed_string,(max_length+2)*sizeof(char)); 
                    //max_length + ' ' + '\0' 
                    if (new_completed_string == NULL)
                    {
                        fprintf(stderr,"[ERROR] Memory Reallocation Problem\n");
                        free(completed_string);
                        free(string_found);
                        free(new_string);
                        exit(EXIT_FAILURE);
                    }
                    completed_string = new_completed_string;
                    for (int j = 0; j < string_found_length; j++)
                    {
                        completed_string[completed_string_length+j] = string_found[j];
                    }
                    completed_string[max_length] = ' ';
                    completed_string[max_length+1] = '\0';
                }
                free(new_string);
            } 

            if (completed_string_length == 0)
            {
                char *new_string = realloc(completed_string,(string_found_length+3)*sizeof(char));
                if (new_string == NULL)
                {
                    fprintf(stderr,"[ERROR] Memory Allocation Problem\n");
                    free(completed_string);
                    free(string_found);
                    exit(EXIT_FAILURE);
                }
                completed_string = new_string;
                completed_string[0] = ' ';
                for (int j = 1; j <= string_found_length; j++)
                {
                    completed_string[j] = string_found[j-1];
                }
                completed_string[string_found_length+1] = ' ';
                completed_string[string_found_length+2] = '\0';
            }
            printf("[DEBUG]completed string = %s\n", completed_string);
            free(string_found);
            i++;
        }
        printf ("[DEBUG]str[%d]%c\n", i,str[i]);
    } 
    int completed_string_length = strlen(completed_string);
    char *new_completed_string = realloc(completed_string,completed_string_length*sizeof(char));
    if (new_completed_string == NULL)
    {
        fprintf(stderr,"[ERROR] Memory Allocation Problem\n");
        exit(EXIT_FAILURE);
    }
    completed_string = new_completed_string;
    completed_string[completed_string_length-1] = '\0';
    printf("[DEBUG]cmpstrlen=%d\n", completed_string_length);
    printf("C%s\n", completed_string);
    free(completed_string);
    printf("[DEBUG] -- end of codomain --\n");   
}
