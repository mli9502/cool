class Main inherits IO {
    a : Int <- 2;
    b : Bool <- false;
    main(): SELF_TYPE {
        {
            (if not b then out_string("not b is true\n") else out_string("not b is false\n") fi);
            if a = 0 then out_string("0\n") else
                if a = 1 then out_string("1\n") else
                    if a = 2 then out_string("2\n") else
                        out_string("not 0, 1, 2\n") 
                    fi 
                fi 
            fi;
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
