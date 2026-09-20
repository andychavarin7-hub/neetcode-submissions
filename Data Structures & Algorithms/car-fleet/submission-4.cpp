class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        struct Prop {
            int pos;
            int speed;
            double time;
            Prop(int a, int b, int target) : pos(a), speed(b) {
                time = double(target-pos)/double(speed);
            };
            bool operator<(const Prop& rhs) {
                return  pos > rhs.pos;  // sort in decending pos order
            }
        };

        std::vector<Prop> carProp{};
        std::stack<double> times{};

        for (auto ii = 0; ii < speed.size(); ++ii) {
            carProp.push_back(Prop(position[ii], speed[ii],target));
        }
        std::sort(carProp.begin(), carProp.end());

        //std::cout << "sorted values are: \n";
        for(auto &ref: carProp){
            //std::cout << "(pos, speed) : (" << ref.pos << ", " << ref.speed << ")" << std::endl;          
            if(times.empty()){
                times.push(ref.time);
            } else if( ref.time > times.top()){
                times.push(ref.time);
            } else{

            }

        }
       //std::cout << "size of fleets: " << times.size() << std::endl;
        return times.size();
    }
};
