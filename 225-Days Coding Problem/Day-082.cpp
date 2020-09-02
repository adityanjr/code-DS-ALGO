class Reader{
    private:
        string raw_data;
        string buffer;
        int processed_till;
        string read7(){
            int start = processed_till; // point from where we have to read the file 
            int end = min(processed_till+7, (int)raw_data.size());
            int old_start_point = start; 
            processed_till = end;  // updated till where file is read 
                                  // so that next time we can start from the same point 
            return raw_data.substr(old_start_point, end);
        }
    public:
        Reader(const string & refString): raw_data(refString), buffer(""), processed_till(0) { }
        string readN(int n) {
            while (int(buffer.size()) < n) {
                string get_char = read7();
                if (get_char == "") { // no more characters are remaining 
                    break;
                }
                buffer += get_char;
            }
            int end_point = min((int)buffer.size(), n);
            string to_be_returned = buffer.substr(0, end_point);
            if(end_point <= (int)buffer.size()){
                buffer = buffer.substr(end_point, (int)buffer.size());
            }
            return to_be_returned;
        }
};
