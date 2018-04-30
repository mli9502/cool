class Main inherits IO {
   main(): SELF_TYPE {
       self
   };
};

class A {
    m1() : Int {
        0
    };
    m2() : Int {
        5
    };
};

class B inherits A {
    m1() : Int {
        1
    };
    m3() : Int {
        2
    };
};

class C inherits A {
    m3() : Int {
        4
    };
};