#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool injective (int inj_line)
{
    node_t *test = request_node(inj_line);
    
    for(int i = 1; test->deserialized_value[i] != NULL; i=i+2)
    {
        printf ("[DEBUG]%s\n", test->deserialized_value[i]);
        for (int j = i+2; test->deserialized_value[j] != NULL; j=j+2)
        {
            if (strcmp(test->deserialized_value[i],test->deserialized_value[j]) == 0)
            {
                if (strcmp(test->deserialized_value[i-1],test->deserialized_value[j-1]) != 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main ()
{
  node_t *test = request_node(inj_line);
}
