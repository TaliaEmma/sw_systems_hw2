#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TXT 1024
#define WORD 30

const char a_z[] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
const char A_Z[] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


void func_a(char w[WORD], char t[TXT] )
{
	int sum=0, i=0, sum2=0, j=0, x=0, k=0;
	char str[TXT];
	
	printf("Gematria Sequences: ");
	
	while(w[i] != '\0')
	{
		if(w[i]>64 && w[i]<91)
			sum += w[i]-64;
		else if(w[i]>96 && w[i]<123)
			sum += w[i]-96;
		i++;		
	}
	i=0;
	
	while(t[i] != '\0')
	{
		while(sum2 < sum && t[j] != '\0')
		{
			if(t[j]>64 && t[j]<91)
				sum2 += t[j]-64;
			else if(t[j]>96 && t[j]<123)
				sum2 += t[j]-96;
			else if( sum2 == 0)  //t[j] == ' ' &&
				break;
			j++;	
		}

		if(sum2 == sum)
		{
			for(x=i; x<j; x++)
			{
				str[k]=t[x];
				k++;
			}	
			str[k]='~';
			k++;
		}
		sum2=0;
		i++;
		j=i;
		
	}
	str[k-1]='\0';
	printf("%s\n", str);

}


void func_b(char w[WORD], char t[TXT] )
{
	int i=0, j=0, k=0, x=0, len=0, k2=0, x2=0, u=1, y=0, r=0,z=0;
	char st1[WORD],st2[WORD], str[TXT], temp[TXT], help[TXT], temp2[TXT], help2[TXT];
	
	printf("Atbash Sequences: ");
	
	while(w[i] != '\0')
	{
		if(w[i]>64 && w[i]<91)
		{
			st1[i]=A_Z[90-w[i]];
		}
		else if(w[i]>96 && w[i]<123)
		{
			st1[i]=a_z[122-w[i]];
		}
		i++;
	}
	st1[i]='\0';
	i=0;
	len=strlen(st1)-1;
	
	while(st1[i] != '\0')
	{
		st2[i]=st1[len-i];
		i++;	
	}
	st2[i]='\0';
	i=0;
	
	while(t[i] != '\0')
	{
		
		while(t[j] != '\0' )
		{
			
			if((t[j] == st1[y]) )
			{
				temp[k]=t[j];
				y++;	
			}
			else if(k !=0  && t[j] == ' ' )   //&& k != strlen(st1)
			{
				temp[k]=t[j];
			}
			else
			{
				break;
			}
			
			k++;
			j++;
				
		}
		
		while(t[z] != '\0' )
		{
			
			if((t[z] == st2[u]) )
			{
				temp2[r]=t[z];
				u++;	
			}
			else if(r !=0  && t[z] == ' ' )
			{
				temp2[r]=t[z];
			}
			else
			{
				break;
			}
			
			r++;
			z++;
				
		}
		
		temp[k]='\0';
		temp2[r]='\0';
		
		x2=0;
		k2=0;
		while(temp[x2] != '\0')
		{
			
			if(temp[x2] != ' ')
			{
				help[k2]=temp[x2];
				k2++;
			}
			x2++;	
			
		}
		help[k2]='\0';
		
		x2=0;
		k2=0;
		while(temp2[x2] != '\0')
		{
			
			if(temp2[x2] != ' ')
			{
				help2[k2]=temp2[x2];
				k2++;
			}
			x2++;	
			
		}
		help2[k2]='\0';
		
		
		
		if(strcmp(st1,help) == 0)
		{
			x2=0;
			while(temp[x2] != '\0')
			{
				str[x]=temp[x2];
				x++;
				x2++;
			}
			while(str[x-1] == ' ')
			{
				x--;
			}
			str[x]='~';
			x++;	
		}
		else if(strcmp(st2,help2) == 0)
		{
			x2=0;
			while(temp2[x2] != '\0')
			{
				str[x]=temp2[x2];
				x++;
				x2++;
			}
			while(str[x-1] == ' ')
			{
				x--;
			}
			str[x]='~';
			x++;
			
		}
		
		
		x2=0;
		while(temp[x2] != '\0')
		{
			temp[x2]=' ';
			x2++;
		}
		
		x2=0;
		while(temp2[x2] != '\0')
		{
			temp2[x2]=' ';
			x2++;
		}
		
		x2=0;
		while(help[x2] != '\0')
		{
			help[x2]=' ';
			x2++;
		}
		
		x2=0;
		while(help2[x2] != '\0')
		{
			help2[x2]=' ';
			x2++;
		}
		
		i++;
		j=i;
		z=i;
		k=0;
		y=0;
		u=0;
		r=0;
	}
	str[x-1]='\0';
	printf("%s\n", str);
}


void func_c(char w[WORD], char t[TXT])
{
	int i=0, j=0, k=0, x=0, k2=0, x2=0, len=0, p=0, p1=0, p2=0, tl=0,l=0, charCount[TXT]={0}; 
	char st1[WORD], st2[WORD], str[TXT], temp[TXT], tsort[TXT], help[TXT], c;
	
	printf("Anagram Sequences: ");
	
	while(w[i] != '\0')
	{
		
		st1[i]=w[i];
		i++;
	}
	st1[i]='\0';
	i=0;
	len=strlen(st1);
	for(i=0; i<len; i++)
	{	c=st1[i];
		charCount[(int)c]++;
	}
	for(i=0; i<TXT; i++)
		for(j=0; j<charCount[i]; j++)
		{	
			st2[p]=(char)i;
			p++;
		}			          
	
	st2[p]='\0';
	i=0;
	
	for(x2=0; x2<sizeof(charCount)/sizeof(int); x2++)
	{
			charCount[x2]=0;
	}
	
	x2=0;
	i=0;
	j=0;
	p=0;
	
	while(t[i] != '\0')
	{
		
		
		for(j=i; j<len+i+l;)
		{
			if(t[j] != ' ')
			{	
				temp[k]=t[j];	
			}
			else if(k > 0 )
			{	
				temp[k]=t[j];
				l++;
			}
			else
			{
				break;
			}	
			j++;
			k++;
				
		}
		l=0;
		
		
		temp[k]='\0';
		
		tl=strlen(temp);
		for(p1=0; p1<tl; p1++)
		{	
			c=temp[p1];
			charCount[(int)c]++;
		}
		for(p1=0; p1<TXT; p1++)
			for(p2=0; p2<charCount[p1]; p2++)
			{	
				
				tsort[p]=(char)p1;
				p++;
			}
		
		
		tsort[p] = '\0';
		
		x2=0;
		k2=0;
		while(tsort[x2] != '\0')
		{
			
			if(tsort[x2] != ' ')
			{
				help[k2]=tsort[x2];
				k2++;
			}
			x2++;	
			
		}
		help[k2]='\0';
		
		if(strcmp(st2,help) == 0)
		{
			x2=0;
			while(temp[x2] != '\0')
			{
				str[x]=temp[x2];
				x++;
				x2++;
			}
			while(str[x-1] == ' ')
			{
				x--;
			}
			str[x]='~';
			x++;
			
			
		}
		
		
		for(x2=0; x2<sizeof(charCount)/sizeof(int); x2++)
		{
			charCount[x2]=0;
		}
		
		x2=0;
		
		while(tsort[x2] != '\0')
		{
			tsort[x2]=' ';
			x2++;
		}
		
		
		x2=0;
		while(temp[x2] != '\0')
		{
			temp[x2]=' ';
			x2++;
		}
		
		
		
		x2=0;
		while(help[x2] != '\0')
		{
			help[x2]=' ';
			x2++;
		}
		
		x2=0;
		
		
		i++;
		k=0;
		p=0;
		
	}
	str[x-1]='\0';
	printf("%s\n", str);

}


int main()
{
	char c, txt[TXT],word[WORD];
	int i=0;

	//printf("Enter your TXT: \n");
	
	
	c = getchar();
	while(c != ' ' && c != '\n' && c != '\t')
	{
		word[i]= c;
		i++;
		c = getchar();
	}
	word[i]='\0';
	i=0;
	
	
	c = getchar();
	while(c != '~')
	{
		txt[i]= c;
		i++;
		c = getchar();
	}
	txt[i]='\0';
	i=0;
	
	func_a(word, txt);
	func_b(word, txt);
	func_c(word, txt);
	
	
	return 0;
}
