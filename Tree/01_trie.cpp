

#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#define MAX			26

/*############################################################## basic trie */

typedef struct T_NODE {
	int isLeaf;
	char ch;
	T_NODE *child[MAX];
} TNode;

TNode *getNode()
{
	TNode *temp = NULL;

	temp = (TNode *)malloc(sizeof(TNode));
	if (temp != 0) {
		temp->isLeaf = 0;
		temp->ch = '0';

		for(int i=0; i<MAX; ++i)
			temp->child[i] = 0;
	}
	return temp;
}

int haveChild(TNode *head)
{
	if(head == NULL)
		return 0;

	int child = 0;

	for(int i=0; i<MAX; ++i)
	{
		if (head->child[i] != NULL) {
			child = 1;
		}
	}
	return child;
}

void insert_trie(TNode *hd, char *str)
{
	if (hd == NULL || str == NULL)
		return;

	TNode *trie = hd;
	int indx = 0;

	while(*str != '\0')
	{
		indx = *str - 'a';
		if (trie->child[indx] == NULL) {
			trie->child[indx] = getNode();
			trie->child[indx]->ch = *str;			
		}

		trie = trie->child[indx];
		str++;
	}
	trie->isLeaf = 1;
	return;
}

int search_trie(TNode *hd, char *str)
{
	if (hd == NULL || str == NULL)
		return 0;

	if(!haveChild(hd))
		return 0;

	TNode *trie = hd;

	while(*str != '\0')
	{
		trie = trie->child[*str-'a'];

		if(trie == NULL)
			return 0;

		str++;
	}
	return trie->isLeaf;
}

int delete_trie(TNode **hd, char*str)
{
	if (*hd == NULL || str == NULL)
		return 0;

	int indx = *str-'a';

	if (*str)
	{
		if((*hd)->child[indx] != NULL)
		{
			delete_trie(&((*hd)->child[indx]), str+1);
		
			if (!haveChild(*hd) && ((*hd)->isLeaf == 0))
			{
				cout << " " <<(*hd)->ch<<endl;
				free(*hd);
				*hd = NULL;
				return 1;	
			}
			else
				return 0;
		}		
	}
	
	if (*str == '\0' && (*hd)->isLeaf)
	{
		if (!haveChild(*hd))
		{
			cout << " " <<(*hd)->ch<<endl;
			free(*hd);
 			*hd = NULL;				
			return 1;
		} else {
			(*hd)->isLeaf = 0;
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

	TNode *trie = getNode();

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

	cout<<"delete - hello - "<<delete_trie(&trie, str1)<<endl;
	cout<<"search - hello - "<<search_trie(trie, str1)<<endl;
	cout<<"search - helloworld - "<<search_trie(trie, str2)<<endl;
	cout<<"search - hell - "<<search_trie(trie, str3)<<endl;
	cout<<"search - h - "<<search_trie(trie, str4)<<endl;

	cout<<endl;
	
	cout<<"delete - helloworld - "<<delete_trie(&trie, str2)<<endl;
	cout<<"search - hello - "<<search_trie(trie, str1)<<endl;
	cout<<"search - helloworld - "<<search_trie(trie, str2)<<endl;
	cout<<"search - hell - "<<search_trie(trie, str3)<<endl;
	cout<<"search - h - "<<search_trie(trie, str4)<<endl;

	cout<<endl;

	cout<<"delete - hell - "<<delete_trie(&trie, str3)<<endl;
	cout<<"search - h - "<<search_trie(trie, str4)<<endl;

	cout<<endl;

	cout<<"delete - h - "<<delete_trie(&trie, str4)<<endl;

	cout<<endl;

	cout<<"search - hello - "<<search_trie(trie, str1)<<endl;
	cout<<"search - helloworld - "<<search_trie(trie, str2)<<endl;
	cout<<"search - hell - "<<search_trie(trie, str3)<<endl;
	cout<<"search - h - "<<search_trie(trie, str4)<<endl;

	cout<<endl;
	
	cout<<"delete - hel - "<<delete_trie(&trie, "hel")<<endl;
	cout<<"delete - heli - "<<delete_trie(&trie, "heli")<<endl;
	cout<<"delete - hellowhile - "<<delete_trie(&trie, "hellowhile")<<endl;

	return;
}

/*############################################################## check string */

typedef struct SNODE {
	char ch;
	int isEnd;
	SNODE *child[MAX];
} SNode;

SNode *getObj()
{
	SNode *node = NULL;

	node = (SNode *)malloc(sizeof(SNode));
	if (node != NULL) {
		node->ch = '\0';
		node->isEnd = 0;

		for(int i=0; i<MAX; ++i)
			node->child[i] = NULL;
	}
	return node;
}

void insert_t(SNode *tri, char *str)
{
	if (tri == NULL || str == NULL)
		return;

	int indx = 0;
	SNode *hd = tri;

	while(*str) 
	{
		indx = *str - 'a';

		if(hd->child[indx] == NULL)
		{
			hd->child[indx] = getObj();
			hd->child[indx]->ch = *str;			
		}

		hd = hd->child[indx];
		str += 1;
	}
	hd->isEnd = 1;
	return;
}

int search_t(SNode *hd, char *str)
{
	int indx = 0;
	SNode *tri = hd;

	while(*str) 
	{
		indx = *str - 'a';

		if(tri->child[indx] == NULL)
			return 0;

		tri = tri->child[indx];
		str += 1;
	}
	return tri->isEnd;
}

void check_string()
{
	char str[] = "this is a bigger string than anything";
	char subs[10][9] = {"this","there","is","pluto","a","strings","bigger","bigs","string","than"};

	SNode *tri = getObj();

	for(auto i=0; i<10; ++i)
		insert_t(tri, subs[i]);

	char *ptr, *rest;

	ptr = strtok_s(str, " ", &rest);

	while(ptr != NULL)
	{
		cout << " "<<ptr<<" - "<<search_t(tri, ptr) << endl;
		ptr = strtok_s(NULL, " ", &rest);
	}

	return;
}

void trie()
{
	/*insert, search, delete in a trie*/
	basic_trie();

	/*Check if given words are present in a string*/
	check_string();
}
