class Main inherits IO {
    a : String <- "Hello World!\n";
   main(): SELF_TYPE {
       {
            out_string(a);
            out_int(9);
            out_string("\n");
            out_string("hello");
            out_string("\n");
            self;
       }
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
