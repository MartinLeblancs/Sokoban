/*
** EPITECH PROJECT, 2020
** my_get_nbr
** File description:
** my_get_nbr
*/

int my_putchar(char c);

int my_put_nbr(int nb);

int  my_getnbr(char  const *str)
{
    int nbr = 0;
    int isneg = 0;
    int i = 0;

    for (i = 0 ; str[i] == '+' || str[i] == '-' ; i++){
        if (str[i] == '-')
            isneg = isneg * -1;
    }
    for ( ; str[i] != '\0' ; i++) {
        if (str[i] >= '0' && str[i] <= '9'){
            nbr = nbr * 10;
            nbr = nbr + str[i] - '0';
        }
        else{
            return (nbr * isneg);
        }
    }
    return (nbr * isneg);
}
