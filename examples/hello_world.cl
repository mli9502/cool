class A {};
class B inherits A {};

class Main inherits IO {
    var : A;
   main(): SELF_TYPE {
       {
           case var of
            a: A => out_string("A class"); -- A class label: 6
            b: B => out_string("B class"); -- B class label: 7
            m: Main => out_string("Main"); -- Main class label: 2
            o: Object => out_string("Object"); -- Object class label: 0
            esac;
            self;
       }
   };
};
