// https://codefights.com/interview-practice/task/6LMyHZbNoXwk4drYi/description

std::vector<int> sortedSquaredArray(std::vector<int> array) {
    int sz=array.size();
    if(sz==0)return array;
    int posElemIndex=find_if(array.begin(),array.end(),[](int i)->bool{
        return i>=0;
    })-array.begin();
    cout<<"Positive Element Index: "<<posElemIndex<<endl;
    vector<int>negSquare(array.begin(),array.begin()+posElemIndex);
    vector<int>posSquare(array.begin()+posElemIndex,array.end());
    transform(negSquare.begin(),negSquare.end(),negSquare.begin(),[](int i)->int{
        return i*i;
    });
    for_each(negSquare.begin(),negSquare.end(),[](int i)->int{
        cout<<i<<" ";
    });
    cout<<endl;
   transform(posSquare.begin(),posSquare.end(),posSquare.begin(),[](int i)->int{
        return i*i;
    });
    for_each(posSquare.begin(),posSquare.end(),[](int i)->int{
        cout<<i<<" ";
    });
    cout<<endl;
    int i=0;
    int j=0;
    array.clear();
    reverse(negSquare.begin(),negSquare.end());
    while(i<negSquare.size() and j<posSquare.size()){
        if(negSquare[i]<=posSquare[j]){
            array.push_back(negSquare[i++]);
        }else array.push_back(posSquare[j++]);
    }
    while(i<negSquare.size())array.push_back(negSquare[i++]);
    while(j<posSquare.size())array.push_back(posSquare[j++]);
    return array;
}
