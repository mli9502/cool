class Main inherits IO {
    a : String;
    b : Int;
    c : Bool;
    test : A;
    main(): SELF_TYPE {
        {
            out_string(a);
            out_string("\n");
            out_int(b);
            out_string("\n");
            if c then out_string("c is true\n") else out_string("c is false\n") fi;
            self;
        }
    };
};

class A {
    a : Int;
    ma() : Int {
        5
    };
};
-- class A {
--     m() : Int {
--         {
--             let x : Int in {
--                 0;
--             };
--         }
--     };
-- };

-- class B inherits A {
--     m() : Int {
--         {
--             let x : Int in {
--                 let y : Int in {
--                     0;
--                 };
--             };
--         }
--     };
-- };


-- class D inherits B {
--     m() : Int {
--         {
--             let x : Int in {
--                 let y : Int in {
--                     let z : Int in {
--                         0;
--                     };
--                 };
--             };
--         }
--     };
-- };


-- class E inherits B {
--     m() : Int {
--         {
--             let x : Int in {
--                 let y : Int in {
--                     let z : Int in {
--                         let xx : Int in {
--                             0;
--                         };
--                     };
--                 };
--             };
--         }
--     };
-- };

-- class C inherits A {
--     m() : Int {
--         {
--             let x : Int in {
--                 let y : Int in {
--                     let z : Int in {
--                         let xx : Int in {
--                             let yy : Int in {
--                                 0;
--                             };
--                         };
--                     };
--                 };
--             };
--         }
--     };
-- };
