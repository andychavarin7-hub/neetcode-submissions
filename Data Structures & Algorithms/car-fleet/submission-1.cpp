class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        struct Prop {
            int pos;
            int speed;
            Prop(int a, int b) : pos(a), speed(b) {};
            bool operator<(const Prop& rhs) {
                return  pos > rhs.pos;  // sort in decending pos order
            }
        };

        std::vector<Prop> carProp{};
        std::stack<double> times{};

        for (auto ii = 0; ii < speed.size(); ++ii) {
            carProp.push_back(Prop(position[ii], speed[ii]));
        }
        std::sort(carProp.begin(), carProp.end());

        //std::cout << "sorted values are: \n";
        for(auto &ref: carProp){
            //std::cout << "(pos, speed) : (" << ref.pos << ", " << ref.speed << ")" << std::endl;\

            double timeVal = double(target - ref.pos)/double(ref.speed);
            if(times.empty()){
                times.push(timeVal);
            } else if( timeVal > times.top()){
                times.push(timeVal);
            } else{

            }

        }
       //std::cout << "size of fleets: " << times.size() << std::endl;
        return times.size();
    }
};
