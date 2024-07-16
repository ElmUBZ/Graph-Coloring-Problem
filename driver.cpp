#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //used for .sort()

using namespace std;

class Vertex {

public:
	Vertex() {}
	Vertex(int m) { name = m; }

	void setName(int n) { name = n; }
	void setColor(int m) { color = m; }
	void addToAdjList(int j) { adjTo.push_back(j); }

	int getName() { return name; }
	int getColor() { return color; }
	vector<int> getAdjList() { return adjTo; }

private:
	int name; //name of vertex
	int color = -1; //name of color
	vector<int> adjTo; //a list of points it touches 

};

void printSolution(int n, vector<Vertex>vlist);//declaration so it can be called by findSolution

void findSolution(int n, int m, vector<Vertex> vList) {
	vList.at(0).setColor(1);//point zero always given color 1 privledges
	for (int i = 1; i < vList.size(); i++) {//start at second element
		int currColor = 1;
		vector<int> temp = vList.at(i).getAdjList();
		sort(temp.begin(), temp.end());//sorts so that it does not assign v3 before v2 etc

		for (int j = 0; j < temp.size(); j++) {//iterates thru adjacency list to check the adjacent points' colors
			if (vList[temp[j]].getColor() == currColor) {//if the current color is being used by a neighbor
				j = 0;
				if (currColor < m) {
					currColor++;
				}
				else {
					cout << "\n\tNo color assigment possible";
					return;
				}
			}
		}
		vList[i].setColor(currColor);
	}
	printSolution(n, vList);
}

void printSolution(int n, vector<Vertex> vList) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "\t" << i << ":" << vList[i].getColor() << endl;
	}
}

int main() {

	int m; //m is the number of colors you're constrained by
	int n; //n is the number of verticies you will be given

	cout << "Enter a graph representation: ";
	cin >> m;
	cin >> n;

	vector<Vertex> vList;

	for (int i = 0; i < n; ++i) {//creates n number of verticies
		Vertex temp(i);
		vList.push_back(temp);
	}

	int vi; int vj; char temp3; char temp4;
	do{
		cin >> temp3;
		cin >> vi;
		cin >> vj;
		cin >> temp3;
		//add the verticies to each other's adjacency lists
		
		if (vi != -1) {
			vList.at(vi).addToAdjList(vj);
			vList.at(vj).addToAdjList(vi);
		}
	} while (vi != -1);

	findSolution(n, m, vList); 

	return 0; 
}
