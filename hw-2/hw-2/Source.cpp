#include<iostream>

#include<cmath>

using namespace std;

class Cuboids
{
    // data members

    float height;
    float width;
    float depth;

public:

    // mutator/accesor

    void setH(float height_Cuboids)
    {

        if (height_Cuboids > 0 && height_Cuboids < 35.00)
        {
            height = height_Cuboids;
        }
        else
        {
            height = 1;
        }

    }

    float getH()
    {
        return height;
    }

    void setW(float width_Cuboids)
    {
        if (width_Cuboids > 0 && width_Cuboids < 35.00)
        {
            width = width_Cuboids;
        }
        else
        {
            width = 1;
        }
    }

    float getW()
    {
        return width;
    }

    void setD(float depth_Cuboids)
    {
        if (depth_Cuboids > 0 && depth_Cuboids < 35.00)
        {
            depth = depth_Cuboids;
        }
        else
        {
            depth = 1;
        }
    }

    float getD()
    {
        return depth;
    }

    // parameterized constructor

    Cuboids(float height_Cuboids, float width_Cuboids, float depth_Cuboids)
    {

        setH(height_Cuboids);
        setW(width_Cuboids);
        setD(depth_Cuboids);

        height = height_Cuboids;
        width = width_Cuboids;
        depth = depth_Cuboids;
    }

    Cuboids(float height_Cuboids, float width_Cuboids)
    {
        setH(height_Cuboids);
        setW(width_Cuboids);

        height = height_Cuboids;
        width = width_Cuboids;
        depth = 0;

    }

    Cuboids() // default constructor
    {
        height = 0;
        width = 0;
        depth = 0;
    }

    Cuboids(const Cuboids& obj) // copy constructor
    {
        height = obj.height;
        width = obj.width;
        depth = obj.depth;
    }

    ~Cuboids() // destructor
    {
        cout << "Destructor executed" << endl;
    }

    //implementation of member functions

    void setCuboids(float height_cuboids, float width_cuboids, float depth_cuboids)
    {
        setH(height_cuboids);
        setW(width_cuboids);
        setD(depth_cuboids);

        height = height_cuboids;
        width = width_cuboids;
        depth = depth_cuboids;
    }

    void getCuboids() // getting data from user
    {

        cout << "Enter height: ";
        cin >> height;

        cout << "ENter width: ";
        cin >> width;

        cout << "Enter depth: ";
        cin >> depth;

        cout << endl;
    }

    void putCuboids() // for displaying info. of cuboid
    {
        setH(height);
        setW(width);
        setD(depth);

        cout << "The  data entered by user: " << endl << endl;

        cout << "Height: " << height << "\t"
             << "Width: " << width << "\t"
             << "Depth: " << depth << endl << endl;
    }

    //to calculate the surface area of a cuboids

    float getSurfaceArea()
    {
        setH(height);
        setW(width);
        setD(depth);

        return ((2 * (height * width)) + (2 * (height * depth)) + (2 * (width * depth)));
    
    }

    // to calculate the volume of a cuboids that is height * width * depth

    float getVolume()
    {
        setH(height);
        setW(width);
        setD(depth);

        return (height * width * depth);
    
    }

    //to calculate the space diagonal of a cuboids

    float getSpaceDiagonal()
    {
        setH(height);
        setW(width);
        setD(depth);

        return sqrt((height * height) + (width * width) + (depth * depth));

    }

    // // display all the dimensions, surface area, volume, and space diagonal of a cuboids

    void putCuboidsInfo()
    {

        setH(height);
        setW(width);
        setD(depth);

        cout << "Information of cuboids: " << endl << endl;

        cout << "The surface area is " << getSurfaceArea() << "\t\t" 
             << "The volume is " << getVolume() << "\t\t"
             << "The space diagonal is " << getSpaceDiagonal() << endl << endl;
    
    }

};

int main()
{
    Cuboids obj1, obj2, obj3;

    obj1.getCuboids(); 

    obj2.getCuboids();

    obj3.getCuboids();

    obj1.putCuboids(); 

    obj2.putCuboids();  

    obj3.putCuboids();

    obj1.putCuboidsInfo(); 

    obj2.putCuboidsInfo();

    obj3.putCuboidsInfo();
    

    return 0;
}