/*
Author: Parag Ghorpade

Adjacency Matrix and Adjacency List 
*/

#include<iostream>
using namespace std;

class graph
{
	int v,e,i,j,a[10][10],b[10],l,u,data;
	graph *head[10],*next,*p;

public:
	void create_matrix();
	void display_matrix();
	void create_linklist();
	graph* ins_end(int j);
	void display_linklist();
};

void graph::create_matrix()
{
	cout<<"\nENTER THE NUMBER OF VERTICES:  ";
	cin>>v;

	cout<<"\nENTER THE NAME OF VERTICES: "<<endl;
	for(int i=0;i<v;i++)
		cin>>b[i];

	for(i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			a[i][j]=0;
		}
	}

	cout<<"\nENTER THE NUMBER OF EDGES: ";
	cin>>e;

	for(int i=0;i<e;i++)
	{
		cout<<"ENTER THE END VERTICES OF EDGES:  "<<endl;
		cin>>l>>u;
		a[l-1][u-1]=a[u-1][l-1]=1;
	}
}


void graph::display_matrix()
{
	cout<<"\nTHE ADJACENCY MATRIX IS:";
	for(int i=0;i<v;i++)
	{
		cout<<endl;
		for(int j=0;j<v;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
}


void graph::create_linklist()
{
	for(i=0;i<v;i++)
	{
		head[i]=new graph;
		head[i]->data=b[i];
		head[i]->next=NULL;
	}

	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(a[i][j]==1)
			{
				if(head[i]->next==NULL)
				{
					head[i]->next=add_end(j);
					p=head[i]->next;
				}
				else
				{
					p->next=add_end(j);
					p=p->next;
				}
			}
		}
	}
}


graph* graph::add_end(int j)
{
	int k=j+1;
	graph *temp=new graph;
	temp->data=k;
	temp->next=NULL;
	return temp;
}


void graph::display_linklist()
{
	cout<<"\nADJACENCY LIST IS:\n"<<endl;
	for(i=0;i<v;i++)
	{
		cout<<"FOR VERTEX "<<head[i]->data<<endl;
		cout<<head[i]->data<<" : ";
		for(p=head[i]->next;p->next!=NULL;p=p->next)
		{
			cout<<p->data<<" -> ";
		}
		cout<<p->data;
		cout<<endl;
		cout<<endl;
	}
}



int main()
{
	graph g;
	cout<<"\n========ADJACENCY MATRIX AND ADJACENCY LIST=========="<<endl;
	g.create_matrix();
	g.display_matrix();
	g.create_linklist();
	g.display_linklist();
	return 0;
}



