void domain (char *str)
{
    printf("[DEBUG] -- domain --\n");
    int str_len = strlen(str);
    char *comp_str = malloc(2*sizeof(char));
    comp_str[0] = ' ';
    for (int i = 2; i <= str_len;i++) //Starts with 2 to ignore 'C '
    {
        if (str[i] == '(')
        {
            i++;
            char *str_found = malloc(2*sizeof(char));
            if (str_found == NULL)
            {
                free(comp_str);
                exit(EXIT_FAILURE);
            } 
            str_found[0] = ' ';
            int str_found_len = strlen(str_found);
            printf ("[DEBUG]str_found_len=%d\n", str_found_len);
            for (i = i; str[i] != ' '; i++)
            {
                str_found_len = strlen(str_found);
                char *new_str_found = realloc(str_found,(str_found_len+3)*sizeof(char));
                if (str_found == NULL)
                {
                    free(str_found);
                    free(comp_str);
                    exit(EXIT_FAILURE);
                }
                str_found = new_str_found; 
                str_found[str_found_len] = str[i];
            }
            str_found[str_found_len+1] = ' ';
            str_found[str_found_len+2] = '\0';
            printf("[DEBUG]str_found = %s\n", str_found);
            if(strstr(comp_str,str_found) == NULL)
            {
                int comp_str_len = strlen(comp_str);
                for (int j = 1; str_found[j] != '\0'; j++)
                {
                    comp_str_len = strlen(comp_str);
                    char *new_comp_str = realloc(comp_str,(comp_str_len+2)*sizeof(char));
                    if (new_comp_str == NULL)
                    {
                        free(str_found);
                        free(comp_str);
                        exit(EXIT_FAILURE);
                    } 
                    comp_str = new_comp_str;
                    comp_str[comp_str_len] = str_found[j];
                }
                comp_str[comp_str_len+1] = '\0';
            }
            free(str_found);
        }
    }
    printf ("C%s\n", comp_str);
    free(comp_str);
}

int main ()
{
  node_t test = test->deserialized_value(x); //x si number of line
  domain(test->value);
  return 0;
}
