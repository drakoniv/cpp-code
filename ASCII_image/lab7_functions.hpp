# include "lab7.h"

// Utility functions
void _print(const ASCIIImage& img, bool verbose)
{
    if(verbose)
    {
        cout<<"row: "<<img.row<<endl;
        cout<<"col: "<<img.col<<endl;
        cout<<"valid?: "<<(_check_image_size(img)? "True":"False")<<endl;
        cout<<"data: "<<endl;
    }
    for(int i=0; i<img.row; i++)
    {
        for(int j=0; j<img.col; j++)
            cout<<img.data[i][j];
        cout<<endl;
    }
}

bool _check_image_size(const ASCIIImage& img)
{
    int row, col;
    for(int i=0; i<MAX_IMAGE_SIZE; i++)
    {
        row = i;
        if(img.data[row][0] == 0)
            break;
    }
    for(int i=0; i<MAX_IMAGE_SIZE; i++)
    {
        col = i;
        if(img.data[0][col] == 0)
            break;
    }
    if(row != img.row || col != img.col)
        return false;
    return true;
}

// Function for ploting the ASCIIImage
void plot(const ASCIIImage& img)
{
    cout<<endl;
    _print(img);
    cout<<endl;
}

// FUNCTION 1
/**
 * TODO:
 * Read the file defined by 'path', and initialize the 'img' with the contents of the file.
 * It should return true if it reads & initializes successfully. Otherwise, it should return False.
 * Note:
 * The row number of the ASCII image locates at the 1st line of the file.
 * The column number of the ASCII image locates at the 2nd line of the file.
 * The following contents are the data of the ASCII image.
 * You can assume the data is square and contains no space.
 **/
bool read_image(ASCIIImage& img, const char path[])
{
    ifstream ifs;
    bool status;
    char line;
    int row, col, counter, counter2;
    row = col = counter = 0;
    counter2 = -1;
    ifs.open(path);
    !ifs ? status = false: status = true; //check status of stream
    ifs >> row;
    img.row = row; //row count
    ifs >> col;
    img.col = col; //col count
    while (!ifs.eof()) { //read data while still not reaching eof
        ifs.get(line);
        if(line != '\n') { // skip newline
            img.data[counter2][counter] = line; // insert data to array
            counter++;
        } else {
            counter2++; //change rows
            counter = 0; //reset column counter
        }
    }
    ifs.close(); // close stream
    return status;
}

// FUNCTION 2
/**
 * TODO:
 * Write 'img' into the file defined by 'path' if 'img' is valid.
 * It should return true if it writes successfully. Otherwise, it should return False.
 * The data format should coincide with the notification of FUNCTION 1.
 * Note:
 * You can validate the 'img' with '_check_image_size'.
 * Of course, you can implement your own validation function.
 **/
bool write_image(const ASCIIImage& img, const char path[])
{
    bool status = false;
    ofstream ofs;
    ofs.open(path); //open stream
    if(_check_image_size(img) && ofs) { //check if image size and output path is valid
        status = true; // return true if valid
        ofs << img.row << '\n'; // print row and col
        ofs << img.col << '\n';
        for (int i = 0; i < img.row; i++) {
            for (int j = 0 ; j < img.col; j++) {
                ofs.put(img.data[i][j]);
            }
            ofs.put('\n');
        }
    }
    ofs.close(); //close ofs stream
    return status;
}

// FUNCTION 3
/**
 * TODO:
 * Rotate the 'img' right by 90 degrees.
 * Note:
 * You have to make sure the result is also a valid ASCIIImage.
 **/
void rotate_clockwise(ASCIIImage& img)
{
    // var init
    char tempArr[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE]; // temporary store array
    int temp; // temporary store var


    for (int i = 0; i < MAX_IMAGE_SIZE; i++) { //transpose loop
        for (int j = 0; j < MAX_IMAGE_SIZE; j++) {
            tempArr[j][i] = img.data[i][j];
        }
    }


    temp = img.row; // new row and col after rotate
    img.row = img.col;
    img.col = temp;

    for (int i = 0; i < MAX_IMAGE_SIZE; i++) { // put content from temporary array to original array
        for (int j = 0; j < MAX_IMAGE_SIZE; j++) {
            img.data[i][j] = tempArr[i][j];
        }
    }

    flip_horizontally(img); // flip horizontally after

}

// FUNCTION 4
/**
 * TODO:
 * Flip the 'img' horizontally.
 * Note:
 * You have to make sure the result is also a valid ASCIIImage.
 **/
void flip_horizontally(ASCIIImage& img)
{
    for(int i = 0; i < img.row; i++ ) {
        for (int j = 0; j < img.col/2; j++) {
            char temp; // temporary store var
            temp = img.data[i][j]; //flip image
            img.data[i][j] = img.data[i][(img.col-1)-j];
            img.data[i][(img.col-1)-j] = temp;
        }
    }
}
