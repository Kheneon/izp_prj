void symmetric (char *str)
{
    printf("[DEBUG] -- symmetric --\n");
    int str_len = strlen(str);
    for(int i = 0; i < str_len; i++)
    {
        if (str[i] == '(')
        {
            char *inv_pair = malloc(2*sizeof(char));
            if (inv_pair == NULL)
            {
                exit(EXIT_FAILURE);
            }
            inv_pair[0] = '(';
            int first_len = 0;
            i++;
            for (i = i; str[i] != ' ';i++)
            {
                first_len++;
            }
            i++;
            int second_len = 0;
            for (i=i; str[i] != ')';i++)
            {
                second_len++;
                char *new_inv_pair = realloc(inv_pair,(second_len+2)*sizeof(char));
                if(new_inv_pair == NULL)
                {
                    free(inv_pair);
                    exit(EXIT_FAILURE);
                }
                inv_pair = new_inv_pair;
                inv_pair[second_len] = str[i];
            }
            inv_pair[second_len+1] = ' ';
            i = i - (second_len+first_len+1);
            int inv_pair_len = strlen(inv_pair);
            printf("[DEBUG]inv_pair_len = %d\n", inv_pair_len);
            printf("[DEBUG]i = %d\n", i);
            for (i=i; str[i] != ' ';i++)
            {
                inv_pair_len++;
                char *new_inv_pair = realloc(inv_pair,(inv_pair_len+3)*sizeof(char));
                //+3 -> 'char' + ')' + '\0' 
                if(new_inv_pair == NULL)
                {
                    free(inv_pair);
                    exit(EXIT_FAILURE);
                }
                inv_pair=new_inv_pair;
                inv_pair[inv_pair_len-1] = str[i];
                printf("[DEBUG]inv_pair[%d]=%c\n",inv_pair_len-1,str[i]);
                
            }
            inv_pair[inv_pair_len] = ')';
            inv_pair[inv_pair_len+1] = '\0';
            inv_pair_len=strlen(inv_pair);
            printf("[DEBUG] --%s--\n",inv_pair);
            printf("[DEBUG] inv_pair_len=%d\n",inv_pair_len);
            if (strstr(str,inv_pair) == NULL)
            {
                printf("[DEBUG]String not found >> false\n");
                free(inv_pair);
                return;
            }
            free(inv_pair);
            printf("[DEBUG]i = %s\n", inv_pair);
        }
    }
    printf("[DEBUG]All strings found >> true\n");
    printf("[DEBUG] -- end of symmetric --\n");
}

int main ()
{
  node_t test = test->deserialized_value(x); //x si number of line
  symmetric(test->value);
  return 0;
}
