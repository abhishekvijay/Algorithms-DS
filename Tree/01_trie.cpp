

#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;

#define MAX			26

typedef struct NODE {
	int isLeaf;
	char ch;
	NODE *child[MAX];
} Node;

Node *getNode()
{
	Node *temp = NULL;

	temp = (Node *)malloc(sizeof(Node));
	if (temp != 0) {
		temp->isLeaf = 0;
		temp->ch = '0';

		for(int i=0; i<MAX; ++i)
			temp->child[i] = 0;
	}
	return temp;
}

int haveChild(Node *head)
{
	if(head == NULL)
		return 0;

	int child = 0;

	for(int i=0; i<MAX; ++i)
	{
		if (head->child[i] != NULL)
			child = 1;
	}
	return child;
}

int insert_trie(Node *hd, char *str)
{
	if (hd == NULL || str == NULL)
		return 0;

	Node *trie = hd;

	while(*str != '\0')
	{
		if (trie->child[*str-'a'] == NULL) {
			trie->child[*str-'a'] = getNode();
			trie->ch = *str;
		}

		trie = trie->child[*str-'a'];
		str++;
	}
	trie->isLeaf = 1;
	return 1;
}

int search_trie(Node *hd, char *str)
{
	if (hd == NULL || str == NULL)
		return 0;

	if(!haveChild(hd))
		return 0;

	Node *trie = hd;

	while(*str != '\0')
	{
		trie = trie->child[*str-'a'];

		if(trie == NULL)
			return 0;

		str++;
	}
	return trie->isLeaf;
}

int delete_trie(Node *hd, char*str)
{
	if (hd == NULL || str == NULL)
		return 0;
	
	Node *trie = hd;

	if (*str != '\0')
	{
		if ((trie->child[*str-'a'] != NULL) && 
			 delete_trie(trie->child[*str-'a'], str+1) && 
			 (trie->isLeaf == 0))
		{
			if (!haveChild(trie))
			{
				printf("%c \n", trie->ch);
				free(trie);
				trie = NULL;
				return 1;
			}
			else
				return 0;
		}
	}

	if (*str == '\0' && trie->isLeaf)
	{
		if (!haveChild(trie))
		{
			printf("%c \n", trie->ch);
			free(trie);
			trie = NULL;
			return 1;
		}
		else
		{
			trie->isLeaf = 0;
			return 0;
		}
	}

	return 0;
}

void basic_trie()
{
	char *str1 = "hello";
	char *str2 = "helloworld";
	char *str3 = "hell";
	char *str4 = "h";

	Node *trie = getNode();

	insert_trie(trie, str1);
	insert_trie(trie, str2);
	insert_trie(trie, str3);
	insert_trie(trie, str4);

	cout<<"search - hello - "<<search_trie(trie, str1)<<endl;
	cout<<"search - helloworld - "<<search_trie(trie, str2)<<endl;
	cout<<"search - hell - "<<search_trie(trie, str3)<<endl;
	cout<<"search - h - "<<search_trie(trie, str4)<<endl;
	
	cout<<"search - hel - "<<search_trie(trie, "hel")<<endl;
	cout<<"search - heli - "<<search_trie(trie, "heli")<<endl;
	cout<<"search - hellowhile - "<<search_trie(trie, "hellowhile")<<endl;

	cout<<endl;

	cout<<"delete - hello - "<<delete_trie(trie, str1)<<endl;
	cout<<"delete - helloworld - "<<delete_trie(trie, str2)<<endl;
	cout<<"delete - hell - "<<delete_trie(trie, str3)<<endl;
	cout<<"delete - h - "<<delete_trie(trie, str4)<<endl;

	cout<<endl;

	cout<<"search - hello - "<<search_trie(trie, str1)<<endl;
	cout<<"search - helloworld - "<<search_trie(trie, str2)<<endl;
	cout<<"search - hell - "<<search_trie(trie, str3)<<endl;
	cout<<"search - h - "<<search_trie(trie, str4)<<endl;

	cout<<endl;
	
	cout<<"delete - hel - "<<delete_trie(trie, "hel")<<endl;
	cout<<"delete - heli - "<<delete_trie(trie, "heli")<<endl;
	cout<<"delete - hellowhile - "<<delete_trie(trie, "hellowhile")<<endl;

	return;
}

void trie()
{
	basic_trie();

}
