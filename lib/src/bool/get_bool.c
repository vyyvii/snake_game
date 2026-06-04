/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

bool get_bool(char *type)
{
    return (my_strcmp_no_case(type, "true") == 0) ? true : false;
}

char *give_bool(bool type)
{
    char *out = (type) ? my_strdup("true") : my_strdup("false");;

    return (out) ? out : NULL;
}
