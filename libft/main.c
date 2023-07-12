/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:21:02 by tokazaki          #+#    #+#             */
/*   Updated: 2023/07/12 10:16:13 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include <string.h>

void modify_char(unsigned int index, char *c) {
    // 文字を大文字に変更する
    if (*c >= 'a' && *c <= 'z') {
        *c = *c - 'a' + 'A';
    }
}

int main() {
    char s[] = "Hello, world!";
    
    ft_striteri(s, modify_char);
    
    printf("Modified string: %s\n", s);
    
    return 0;
}
int	main(void)
{
	printf("LONG_MAX\t:%ld\n",LONG_MAX);
	printf("LONG_MIN\t:%ld\n",LONG_MIN);
	printf("ULLONG_MAX\t:%llu\n",ULLONG_MAX);

	char	ts1[] = "12345";
	printf("str\t:%s\tret:%d\n",ts1,atoi(ts1));
	printf("ft_str\t:%s\tret:%d\n\n",ts1,ft_atoi(ts1));
	
	char	ts8[] = "\t\v\f\r\n 12345";
	printf("str\t:%s\tret:%d\n",ts8,atoi(ts8));
	printf("ft_str\t:%s\tret:%d\n\n",ts8,ft_atoi(ts8));

	char	ts9[] = "+12345";
	printf("str\t:%s\tret:%d\n",ts9,atoi(ts9));
	printf("ft_str\t:%s\tret:%d\n\n",ts9,ft_atoi(ts9));

	char	ts2[] = "123456789012345678901";
	printf("str\t:%s\tret:%d\n",ts2,atoi(ts2));
	printf("ft_str\t:%s\tret:%d\n\n",ts2,ft_atoi(ts2));
	
	char	ts3[] = "12a345";
	printf("str\t:%s\tret:%d\n",ts3,atoi(ts3));
	printf("ft_str\t:%s\tret:%d\n\n",ts3,ft_atoi(ts3));
	
	char	ts4[] = "2147483646";
	printf("str\t:%s\tret:%d\n",ts4,atoi(ts4));
	printf("ft_str\t:%s\tret:%d\n\n",ts4,ft_atoi(ts4));
	
	char	ts10[] = "2147483647";
	printf("str\t:%s\tret:%d\n",ts10,atoi(ts10));
	printf("ft_str\t:%s\tret:%d\n\n",ts10,ft_atoi(ts10));
	
	char	ts5[] = "922337203685477580500";
	printf("str\t:%s\tret:%d\n",ts5,atoi(ts5));
	printf("ft_str\t:%s\tret:%d\n\n",ts5,ft_atoi(ts5));
	
	char	ts6[] = "9223372036854775809";
	printf("str\t:%s\tret:%d\n",ts6,atoi(ts6));
	printf("ft_str\t:%s\tret:%d\n\n",ts6,ft_atoi(ts6));
	
	char	ts11[] = "-9223372036854775809";
	printf("str\t:%s\tret:%d\n",ts11,atoi(ts11));
	printf("ft_str\t:%s\tret:%d\n\n",ts11,ft_atoi(ts11));
	
	char	ts7[] = "-9223372036854775805";
	printf("str\t:%s\tret:%d\n",ts7,atoi(ts7));
	printf("ft_str\t:%s\tret:%d\n\n",ts7,ft_atoi(ts7));
	
	char	ts18[] = "9223372036854775805";
	printf("str\t:%s\tret:%d\n",ts18,atoi(ts18));
	printf("ft_str\t:%s\tret:%d\n\n",ts18,ft_atoi(ts18));
}

int main() {
    char src[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char dst[] = "bbbbbb";
    char dst2 [] = "bbbbbb";
	int j = 4;
	int i = 1;
	write(1,"a",1);
   size_t len = strlcat(dst, src, j);
	write(1,"a",1);
    size_t len2 = ft_strlcat(dst2, src, j);
	write(1,"a",1);

    printf("Copied string: %s\n", dst);
    printf("Length: %zu\n", len);
	printf("null: %d\n\n", dst[i]);
   
	printf("Copied string: %s\n", dst2);
    printf("Length: %zu\n", len2);
	printf("null: %d\n", dst2[i]);
    return 0;
}
int main()
{
        char    buff[10];
        int     i1;

        for (i1 = 0; i1 < 10; i1++)
                buff[i1] = i1;
        printf("1.");
        for (i1 = 0; i1 < 10; i1++)
        {
                printf("[%d]", buff[i1]);
        }
        printf("\n2.");

       memmove(buff + 2, buff, 8);

        for (i1 = 0; i1 < 10; i1++)
        {
                printf("[%d]", buff[i1]);
        }

        for (i1 = 0; i1 < 10; i1++)
        {
                buff[i1] = i1;
        }

        printf("\n3.");
        for (i1 = 0; i1 < 10; i1++)
        {
                printf("[%d]", buff[i1]);
        }
        printf("\n4.");

        ft_memmove(buff + 2, buff, 8);

        for (i1 = 0; i1 < 10; i1++)
        {
                printf("[%d]", buff[i1]);
        }
}
int main (void)//memcmp
{
    char buf[] = "ABC9EFGH";
    char buf2[] = "ABC123456";
	int i = 5;
    printf("exp:%d \n",memcmp(buf, buf2, i));
	printf("act:%d \n",ft_memcmp(buf, buf2, i));
    return 0;
}

int	main (void)
//int	main(int argc, char *argv[])
{
//	strdup検証用
//	argc = 0;
	int i = 0;
	int	j = 2;
	int y = 0;
//	char b = 'a'
	char c[5] = {'a','b','0','0','b'};
//	char c[1] = {'\0'};
//	char *c = {NULL};
//	char *c = argv[1];
	write (1,"3\n",2);
	char *ft_str = ft_strdup(c);
	char *str = (c);//stddupにNULLを入れるとセグフォ
	char nullChar = '\0';
	if (str[j] == nullChar)
		i = 1;
	if (ft_str[j] == nullChar)
		y = 1;

	printf("数字:%d \n", j);
	printf("文字:%d \n", ft_str[j]);
	printf("NUll:%d \n", y);
	printf("文字:%d \n", str[j]);
	printf("NUll:%d \n", i);
//	printf("act:%d \n", ft_isprint(31));

	return (0);
}
*/
