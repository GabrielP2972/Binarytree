#include <iostream>
using namespace std;

template<class T>
class bintree{
    private: 
        T info;
        bintree<T>* hijoD;
        bintree<T>* hijoI;
    public:

        bintree(T info){
            this->info=info;
            hijoD=NULL;
            hijoI=NULL;cout<<"x"<<endl;
        }

        bintree(){
            info=NULL;
            hijoD=NULL;
            hijoI=NULL;
        }

        //~bintree(){}

        T getinfo(){
            return info;
        } 

        bintree<T>* getNode(T info){
            if( info == this->info )
                return this;
        
            bintree<T>* ans = NULL;

            if (info < this-> info)
                ans = hijoI->getNode(info);

            if (info > this-> info)
                ans =hijoD->getNode(info);

            if( ans != NULL )
                return ans;

            return NULL;
        }

        bintree<T>* get_node(T info){
            if( info == this->info)
                return this;

            bintree<T>* ans = NULL;

            if(hijoI != NULL)
                ans = hijoI->get_node(info);

            if(hijoD != NULL)
                ans = hijoD->get_node(info);

            if(ans != NULL)
                return ans;

            return NULL;
        }

        void insertI(T info){
            hijoI = new bintree<T>(info);cout<<"y"<<endl;
        }

        void insertD(T info){
            hijoD = new bintree<T>(info);cout<<"y"<<endl;
        }

        void insert(T info, T dad){
            bintree<T>* father;
            father = getNode(dad);
            if(info < dad)
                father->insertI(info);
            if(info > dad)
                father->insertI(info);
        }

        void insert(T info, T dad, bool dir){
            cout<<"b"<<endl;
            bintree<T>* father;cout<<"i"<<endl;
            father = get_node(dad);cout<<"f"<<endl;
            if(dir){cout<<"c"<<endl;
                father->insertD(info);  
            }else{cout<<"d"<<endl;
                father->insertI(info);}cout<<"z"<<endl;
        }

        void printPreorder(){
            cout<< info <<"  ";
            if(hijoI != NULL)hijoI->printPreorder();
            if(hijoD != NULL)hijoD->printPreorder();
        }

        void printPostorder(){
            if(hijoI != NULL)hijoI->printPostorder();
            if(hijoD != NULL)hijoD->printPostorder();
            cout<< info << "  ";
        }

        void printInorder(){
            if(hijoI != NULL)hijoI->printInorder();
            cout<< info << "  ";
            if(hijoD != NULL)hijoD->printInorder();
        }

        void printZigZag(bool dir=0, bool prev=0, bool prin=0){//1, 2, 3, 4, 5, 6, 7 formato
            // dir=0 ->  dir=1 <-  
            if(prin)cout<<info<<", ";
            if(!dir && !prev){//0 0
                if(hijoI != NULL)cout<<hijoI->info<<", ";
                hijoD->printZigZag(1, 1, 1);
                hijoI->printZigZag(1,0);
            }
            if(!dir && prev){//0 1
                if(hijoI != NULL)cout<<hijoI->info<<", ";
                if(hijoD != NULL)cout<<hijoD->info<<", ";
                return;
            }
            if(dir && prev){//1 1
                if(hijoD != NULL)cout<<hijoD->info<<", ";
                if(hijoI != NULL)cout<<hijoI->info<<", ";
                return;
            }
            if(dir && !prev){//1 0
                if(hijoD != NULL)cout<<hijoD->info<<", ";
                hijoI->printZigZag(0,1,1);
                hijoD->printZigZag(0,0);
            }
        }
};
