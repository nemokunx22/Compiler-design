#include<stdio.h>

int n, m=0, cls[10];
char trans[20][20], states[10], closure[10][10];

void add(char, char *, int*);
int search(char, char *, int);
int epsClosure(char, int);

int main()
{
	int i,j;
	printf("Enter the number of transitions: ");
	scanf("%d",&n);
	printf("Enter the transitions (A,a=B) '^' for epsilon:\n");
	for (i=0; i<n; i++)
	{
		scanf("%s",trans[i]);
	}
	for (i=0; i<n; i++)
	{
		add(trans[i][0],states,&m);
		add(trans[i][4],states,&m);
	}
	for (i=0; i<m; i++)
	{
		epsClosure(states[i],0);
	}
	for (i=0; i<m; i++)
	{
		printf("epsilon-closure(%c) = {",states[i]);
		for (j=0; j<cls[i]-1; j++)
		{
			printf(" %c,",closure[i][j]);
		}
		printf(" %c }\n",closure[i][j]);
	}
}
void add(char c, char *p, int *size)
{
	if (search(c,p,*size)==-1)
		p[(*size)++] = c;
}
int search(char c, char *p, int size)
{
	for (int i=0; i<size; i++)
		if(c==p[i])
			return i;
	return -1;
}

int epsClosure(char st, int start)
{
	int index = search(st,states,m);
	add(st,closure[index],&cls[index]);
	for (int i=start; i<n; i++)
	{
		if (trans[i][0]==st && trans[i][2]=='^')
		{
			add(trans[i][4],closure[index],&cls[index]);
			int index2 = epsClosure(trans[i][4],start+1);
			for (int j=0; j<cls[index2]; j++)
			{
				add(closure[index2][j],closure[index],&cls[index]);
			}
		}
	}
	return index;
}
