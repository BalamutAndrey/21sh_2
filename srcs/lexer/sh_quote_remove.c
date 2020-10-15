/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_quote_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:00:27 by geliz             #+#    #+#             */
/*   Updated: 2020/10/15 16:03:39 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
typedef struct		s_envvar
{
  int				start;
  int				end;
  int				count;
  struct s_envvar  *next;
}					t_envvar;

int    is_protected(char *str, int i)
{
  int    j;
  int    ret;

  j = 0;
  while (i > 0 && str[i - 1] == '\\')
  {
     i--;
     j++;
  }
  ret = j % 2 == 0 ? 0 : 1;
  return (ret);
}

char  *remove_char(char *str, int i)
{
  char  *ret;
  int    len;
  int    j;

  len = strlen(str);
  j = 0;
  ret = malloc(sizeof(char) * len);
  ret[len - 1] = '\0';
  while (j < len - 1)
  {
    if (j < i)
    {
      ret[j] = str[j];
      j++;
    }
    else 
    {
      ret[j] = str[i + 1];
      j++;
      i++;
    }

  }
//  strdel(str);
//  printf("%s\n", ret);
  return (ret);
}

t_envvar  *create_env()
{
  t_envvar  *ret;

  ret = malloc(sizeof(t_envvar));
  ret->start = -1;
  ret->end = -1;
  ret->next = NULL;
}

void  add_env(char *str, int i, t_envvar *env)
{
  t_envvar  *tmp;
  t_envvar  *prev;

//  printf("add_env\n");
  tmp = create_env();
  prev = env;
  while (prev->next)
    prev = prev->next;
  prev->next = tmp;
  tmp->start = i;
  i++;
  while ((str[i] >= '0' && str[i] <= '9')  || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
  {
    i++;
  }
  tmp->end = i;
}

void  checker(char *str, t_envvar *env)
{
  printf("%s\n", str);
  while (env)
  {
    printf("env_start = %i, env_end = %i\n", env->start, env->end);
    env = env->next;
  }
}

char  *dequot(char *str, int len)
{
  int      i;
  t_envvar  *env;
  int      flag;

  i = 0;
  flag = 0;
  env = create_env();
  while (str[i])
  {
//    printf("%c = str[%i]\n", str[i], i);
    if (str[i] == '\"' && is_protected(str, i) == 0)
    {
      str = remove_char(str, i);
//      printf("first_rem = %s\n", str);
      while (flag == 0)
      {
        if (str[i] == '\\' && (str[i + 1] == '\"' || str[i + 1] == '$') && is_protected(str, i) == 0)
        {
          str = remove_char(str, i);
        }
        else if (str[i] == '$' && is_protected(str, i) == 0)
          add_env(str, i, env);
        i++;
        if (str[i] == '\"' && is_protected(str, i) == 0)
          flag = 1;
      }
      str = remove_char(str, i);
      flag = 0;
//      printf("second_rem = %s\n", str);
    }
    else if (str[i] == '\'' && is_protected(str, i) == 0)
    {
      str = remove_char(str, i);
      while (str[i] != '\'')
        i++;
      str = remove_char(str, i);
    }
    else if (str[i] == '$' && is_protected(str, i) == 0)
    {
      add_env(str, i, env);
      i++;
    }
    else if (str[i] == '\\')
    {
      str = remove_char(str, i);
      i++;
    }
    else
      i++;
  }
  checker(str, env);
}

int    main(void)
{
  char  *str;
  int    len;

  str = readline(">>");
  len = strlen(str);
//  printf("%s\n", str);
  str = dequot(str, len);
  return (0);
}
*/