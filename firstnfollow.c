//AKASH V V
//TLY21CS009
//5-09-24


/*
use ^ for epsilon
= instead of ->
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void removeRepeatChars(char* str)
{
    int len=strlen(str),index=0,i,j;
    for(i=0;i<len;i++) {
        for(j=0;j<i;j++)
            if(str[i]==str[j])
				break;
        if(j==i)
			str[index++]=str[i];
    }
    str[index]='\0';
}

int n,i;
char g[10][200],non[10],fi[10][20],fo[10][20];
int first(char t)
{
	int j,k,x,y=0,z,z1=0,fix=-1,fiw;
	for(k=0;k<n;k++)
		for(j=0;g[k][j]!='\0';j++)
		{
			if((g[k][j]==t)&&(g[k][j+1]=='='))
			{
				if((fi[k][0]!='\0')&&(fix==-1))
					return(k);//(cant use exit)
				fix==-1?fix=k:(void)0;
				non[fix]=t;
				if(!isupper(g[k][j+2]))
					fi[fix][y++]=g[k][j+2];
				else 
				{
					z=2;
					do{
						if(!isupper(g[k][j+z]))
						{
							if(g[k][j+z]!='|')
								fi[fix][y++]=g[k][j+z];
							break;
						}
						fiw=first(g[k][j+z]);
						z++,z1=0;
						for(x=0;fi[fiw][x]!='\0';x++)
						{ 	
							fi[fiw][x]=='^'?z1=1:(void)0;
							fi[fix][y++]=fi[fiw][x];
						}
					}while(z1 && g[k][j+z]!='\0');
				}
				for(j=j+3;g[k][j]!='\0';j++)
					if((g[k][j]=='|')&&(!isupper(g[k][j+1])))
						fi[fix][y++]=g[k][j+1];
					else if((g[k][j]=='|')&&(isupper(g[k][j+1])))
					{
						z=1;
						do{
							if(!isupper(g[k][j+z]))
							{
								if(g[k][j+z]!='|')
									fi[fix][y++]=g[k][j+z];
								break;
							}
							fiw=first(g[k][j+z]);
							z++,z1=0;
							for(x=0;fi[fiw][x]!='\0';x++)
							{
								fi[fiw][x]=='^'?z1=1:(void)0;
								fi[fix][y++]=fi[fiw][x];
							}
						}while(z1 && g[k][j+z]!='\0');
					}
			}	
		}
	fi[fix][y]='\0';
	removeRepeatChars(fi[fix]);
	return(fix);
}
int follow(char t,int fix)
{
	int j,k,x,y=0,z1=0,z,fiw,fiwlhs;
	char lhs;
	if(fo[fix][0]!='\0')
		return(fix);
	if(fix==0)
		fo[fix][y++]='$';
	for(k=0;k<n;k++)
		for(j=2;g[k][j]!='\0';j++)
		{
			lhs=g[k][0];
			fiwlhs=first(lhs);
			if(g[k][j]==t && g[k][j+1]!='=')
			{
				fo[fix][y]='\0';
				if(g[k][j+1]=='\0')
				{
					follow(lhs,fiwlhs);
					for(x=0;fo[fiwlhs][x]!='\0';x++)
						fo[fix][y++]=fo[fiwlhs][x];
					break;	
				}
				if(g[k][j+1]=='|')
				{
					follow(lhs,fiwlhs);
					for(x=0;fo[fiwlhs][x]!='\0';x++)
						fo[fix][y++]=fo[fiwlhs][x];
					j++; continue;	
				}
				if(!isupper(g[k][j+1]))
					fo[fix][y++]=g[k][j+1];
				if(isupper(g[k][j+1]))
				{
					z=1;
					do{
						if(!isupper(g[k][j+z]))
						{
							if((g[k][j+z]!='|')&&(g[k][j+z]!='^'))
								fo[fix][y++]=g[k][j+z];
							else if(g[k][j+z]=='|')
							{
								fo[fix][y]='\0';
								follow(lhs,fiwlhs);
								for(x=0;fo[fiwlhs][x]!='\0';x++)
									fo[fix][y++]=fo[fiwlhs][x];
							}
							break;
						}
						fiw=first(g[k][j+z]);
						z1=0;z++;
						for(x=0;fi[fiw][x]!='\0';x++)
							if(fi[fiw][x]=='^')
								z1=1;
							else
								fo[fix][y++]=fi[fiw][x];
					  }while(z1 && g[k][j+z]!='\0');
					if(isupper(g[k][j+z-1])&&z1&&g[k][j+z]=='\0')
					{
						fo[fix][y]='\0';
						follow(lhs,fiwlhs);
						for(x=0;fo[fiwlhs][x]!='\0';x++)
							fo[fix][y++]=fo[fiwlhs][x];
					}
				}
			}
		}
	fo[fix][y]='\0';
	removeRepeatChars(fo[fix]);
	return(fix);
}
int main()
{
	int x,y;
	char w[10][200],inp[10];
	printf("Enter number of lines in grammar: ");
	scanf("%d",&n);
	printf("Enter grammar('^' for null):-\n");
	char ch=getchar();
	for(i=0;i<n;i++)
	{
		scanf("%[^\n]",w[i]);
		ch=getchar();
		for(x=0,y=0;w[i][x]!='\0';x++)
			if((w[i][x]!=' ')&&(w[i][x]!='\t'))
				g[i][y++]=w[i][x];
		g[i][y]='\0';
		inp[i]=g[i][0];
		fi[i][0]=fo[i][0]=non[i]='\0';
	}
	printf("\n");
	for(i=0;i<n;i++)
		first(inp[i]);
	for(i=0;i<n;i++)
	{
		if(non[i]=='\0') continue;
		printf("First(%c) = {",non[i]);
		for(x=0;fi[i][x]!='\0';x++)
		{
			printf(" %c ",fi[i][x]);
			if(fi[i][x+1]!='\0')
				printf(",");
		}
		printf("}\n");
	}
	printf("\n");
	for(i=0;i<n;i++)
		if(non[i]!='\0')
			follow(non[i],i);
	for(i=0;i<n;i++)
	{
		if(non[i]=='\0') continue;
		printf("Follow(%c) = {",non[i]);
		for(x=0;fo[i][x]!='\0';x++)
		{
			printf(" %c ",fo[i][x]);
			if(fo[i][x+1]!='\0')
				printf(",");
		}
		printf("}\n");
	}
}
