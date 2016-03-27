/*************************************************************************
 * Author:          sugarfreeoh
 * Date:            25 March 2016
 * Description:     Each line contains the list of cities and distances
 *                  to them, from the starting point of the trip. The 
 *                  trip starts at point 0. Print out the distances from
 *                  the starting point to the nearest city.
 *************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream inputFile;
    
    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;

        while(getline(inputFile,line))
        {
            stringstream ss;
            string temp;
 
            vector<unsigned int> distances;

            unsigned int minDistance;
            unsigned int startingPoint = 0;
            unsigned int index = 0;
            unsigned int tempDist;

            ss << line;

            while(getline(ss,temp,';'))
            {
                stringstream citySS;
                
                size_t delLocation;

                if(temp[0] == ' ')
                {
                    temp = temp.substr(1);
                }
                
                delLocation = temp.find(',');

                citySS << temp.substr(delLocation+1);

                citySS >> tempDist;

                distances.push_back(tempDist);
            }

            sort(distances.begin(),distances.end());

            while(index < distances.size())
            {
                minDistance = distances[index] - startingPoint;

                if(index < distances.size()-1)
                {
                    cout << minDistance << ",";
                }
                else
                {
                    cout << minDistance << endl;
                }

                startingPoint = distances[index];

                ++index;
            }
        }
    }
    else
    {
        cout << "Error opening input file" << endl;
    }

    return 0;
}
