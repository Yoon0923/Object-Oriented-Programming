#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<random>

using namespace std;

//------------------------PROTOTYPE-------------------------------------------
int ranGen(int);
bool readFile(string, vector<string> &);
bool writeFile(string, const vector<string> &, const vector<string> &);
void promptFile(vector<string> &); 
void printVec(vector<string>);

/**
 * @brief generates a random question 
 * index based on the size of the question bank
 * @return int random index from 0 to size - 1
 */
int ranGen(int size){
   random_device rd; 
   mt19937 gen(rd()); 
   uniform_int_distribution<> distr(0, size - 1); 
   return distr(gen);
}
/**
 * @brief reads contents of filename and populates into vec
 * 
 * @param filename :string 
 * @param vec: vector<string> &
 * 
* @return true if the file was read successfully, false otherwise
 */
bool readFile(string filename, vector<string> & vec) {

   ifstream inputFile(filename);

    //error handling
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file\n";
        return false;
    }

    string line;

    while (getline(inputFile, line)) {
        vec.push_back(line);
    }

    inputFile.close();
    return true;
}
/**
 * @brief writes to filename with the first column from v0, second column from v1
 * 
 * @param filename: string
 * @param v0: vector<string> (for students names)
 * @param v1: vector<string> (for questions)
 * @return true if the file was written successfully, false otherwise
 */
bool writeFile(string filename, const vector<string> & v0, const vector<string> & v1){

    ofstream outputFile(filename);
     if (!outputFile) {
        cout << "Error: Could not create data.csv" << endl;
        return false;
    }

    // write under the structure:
    // Student_Name, Question_#
    for(int i = 0; i < v0.size(); i++){
        outputFile << v0[i] << "," << v1[ranGen(v1.size())] << endl;
    }
    outputFile.close();
    return true;
}


int main()
{
    srand(time(nullptr));
    vector<string> roster;
    vector<string> qBank;
    readFile("2310_F26_Rosters.csv", roster);
    readFile("Questions.csv", qBank);
    // printVec(roster);
    // printVec(qBank);

    // cout << "Size of roster: " << roster.size() << endl; 
    // cout << "Size of qBank: " << qBank.size() << endl;

    writeFile("Student_question_bank.csv",roster, qBank);

}

//------------------------DECLARATIONS-------------------------------------------
/**
 * @brief prompts the user to give a file to read
 * 
 */
void promptFile(vector<string> & v){
    cout << "file to read?\n";
    string myFile = "";
    cin >> myFile;
    readFile(myFile, v);
}


/**
 * @brief prints out the elements in v
 * 
 * @param v: vector<string>
 */
void printVec(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}