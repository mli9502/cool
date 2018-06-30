-- class Main inherits IO {
--     a : A <- new B;
--     y : Int <- 0;
--     main(): SELF_TYPE {
--         {
--             -- ************************************
--             -- Test let expression...
--             -- (let position : Int <- 1 in
--             --     {
--             --         (let num : Int <- 2 in
--             --             (let temp : String <- "temp" in
--             --                 {
--             --                     out_int(position);
--             --                     out_string("\n");
--             --                     out_int(num);
--             --                     out_string("\n");
--             --                     out_string(temp);
--             --                     out_string("\n");
--             --                 }
--             --             ) 
--             --         );
--             --         out_string("first let\n");
--             --         out_int(position);
--             --         out_string("\n"); 
--             --     }
--             -- );
--             -- ************************************

--             -- ************************************
--             -- Test isvoid, type_name and dispatch to method in trap_handler.
--             out_string((isvoid self).type_name());
--             out_string("\n");
--             out_string((isvoid self).type_name().substr(1, 3));
--             out_string("\n");
--             self;
--             -- ************************************

--             -- ************************************
--             -- Test dynamic dispatch.
--             a.ma(1, 2);
--             out_int((new A).ma(3, 4));
--             out_string("\n");
--             self;
--             -- ************************************

--             -- ************************************
--             -- Test case.
--             case a of
--                 a_A : A => {
--                     out_string("class type is now A\n");
--                 };
--                 a_B : B => {
--                     out_string("class type is now B\n");
--                     case a of
--                         a_B_A : A => out_string("a_B_A\n");
--                         a_B_B : B => {
--                             (let position : Int <- 1 in
--                                 {
--                                     (let num : Int <- 2 in
--                                         (let temp : String <- "temp" in
--                                             {
--                                                 out_int(position);
--                                                 out_string("\n");
--                                                 out_int(num);
--                                                 out_string("\n");
--                                                 out_string(temp);
--                                                 out_string("\n");
--                                             }
--                                         ) 
--                                     );
--                                     out_string("first let\n");
--                                     out_int(position);
--                                     out_string("\n"); 
--                                     a_B.ma(2, 3);
--                                     a_B_B.ma(1, 4);
--                                 }
--                             );    
--                         };
--                         a_B_O : Object => out_string("a_B_O\n");
--                     esac;
--                 };
--                 a_O : Object => out_string("class type is Object\n");
--             esac;
--             self;
--             -- ************************************
--         }
--     };
-- };

-- class A inherits IO {
--     a : Int <- 10;
--     getA() : Int {
--         a
--     };
--     ma(i: Int, j: Int) : Int {
--         {
--             out_string("A::i: ");
--             out_int(i);
--             out_string("\nA::j: ");
--             out_int(j);
--             out_string("\n");
--             a;
--         }
--     };
-- };
-- class B inherits A {
--     ma(i: Int, j: Int) : Int {
--         {
--             out_string("B::i: ");
--             out_int(i);
--             out_string("\nB::j: ");
--             out_int(j);
--             out_string("\n");
--             a;
--         }
--     };
-- };
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

-- class A {
--     a : String;
--     getA() : String {
--         a
--     };
-- };

-- class Main inherits IO{
-- 	main():Object {{
-- 		-- if (true = false) then abort() else 0 fi;
-- 		-- if (true = true) then 0 else abort() fi;
-- 		-- if ("hello" = "hello".copy()) then 0 else abort() fi;
-- 		let a:A <- new A in if (a.getA() = "") then 0 else abort() fi;
-- 		-- if 5 = 6 then abort() else 0 fi;
-- 	}};

-- };


-- new SELF_TYPE creates an object with the same dynamic type as self,
-- which affects initialization of the new object's attributes.



-- (* hairy  . . .*)

-- class Second inherits First {};

-- class First inherits IO {

--     --  h : Int <- ({out_string("First::h\n"); 1;});

--      g : Second  <- case self of
-- 		     	n : First => ({out_string("First::First\n"); new Second;});
-- 				n : Second  => ({out_string("First::Second\n"); n;});
-- 		  		esac;

--     --  i : Object <- ({out_string("First::i\n");});

--     --  printh() : Int { { out_int(h); 0; } };

--     --  doh() : Int { (let i: Int <- h in { h <- h + 1; i; } ) };
-- };

-- (* scary . . . *)
-- class Main {
--   a : First <- new First;
-- --   b : Second <- new Second;
-- --   c : Third <- new Third;
-- --   d : Fourth <- new Fourth;

--   main(): String { "do nothing" };

-- };



-- (* hairy  . . .*)

-- class Foo inherits Bazz {
--      a : Razz <- case self of
-- 		      n : Razz => (new Bar);
-- 		      n : Foo => (new Razz);
-- 		      n : Bar => n;
--    	         esac;

--      b : Int <- a.doh() + g.doh() + doh() + printh();

--      doh() : Int { (let i : Int <- h in { h <- h + 2; i; } ) };

-- };

-- class Bar inherits Razz {

--      c : Int <- doh();

--      d : Object <- printh();
-- };


-- class Razz inherits Foo {

--      e : Bar <- case self of
-- 		  n : Razz => (new Bar);
-- 		  n : Bar => n;
-- 		esac;

--      f : Int <- a@Bazz.doh() + g.doh() + e.doh() + doh() + printh();

-- };

-- class Bazz inherits IO {

--      h : Int <- 1;

--      g : Foo  <- case self of
-- 		     	n : Bazz => (new Foo);
-- 		     	n : Razz => (new Bar);
-- 			n : Foo  => (new Razz);
-- 			n : Bar => n;
-- 		  esac;

--      i : Object <- printh();

--      printh() : Int { { out_int(h); 0; } };

--      doh() : Int { (let i: Int <- h in { h <- h + 1; i; } ) };
-- };

-- (* scary . . . *)
-- class Main {
--   a : Bazz <- new Bazz;
--   b : Foo <- new Foo;
--   c : Razz <- new Razz;
--   d : Bar <- new Bar;

--   main(): String { "do nothing" };

-- };


-- Dynamically dispatching on a void object is a runtime error.


-- class Main inherits IO
-- {
--   main() : Object
--   {
--     let nothing : Object <- while false loop 1 pool in
--       out_string(nothing.type_name())
--   };
-- };

-- class Main {
-- 	x:Main;
-- 	main():Object { { case x of m:Main => 0; esac; } };
-- };


-- calls.cl

(* A program for

   1. Representing lambda terms
   2. Interpreting lambda terms
   3. Compiling lambda calculus programs to Cool

   The lambda calculus is described by the following grammar:

   e ::= x	       a variable
      |  \x.e	       a function with argument x
      |  e1@e2	       apply function e1 to argument e2

  Jeff Foster
  March 24, 2000
*)

(*
 * A list of variables.  We use this to do de Bruijn numbering
 *
 *)
class VarList inherits IO {
  isNil() : Bool { true };
  head()  : Variable { { abort(); new Variable; } };
  tail()  : VarList { { abort(); new VarList; } };
  add(x : Variable) : VarList { (new VarListNE).init(x, self) };
  print() : SELF_TYPE { out_string("\n") };
};

class VarListNE inherits VarList {
  x : Variable;
  rest : VarList;
  isNil() : Bool { false };
  head()  : Variable { x };
  tail()  : VarList { rest };
  init(y : Variable, r : VarList) : VarListNE { { x <- y; rest <- r; self; } };
  print() : SELF_TYPE { { x.print_self(); out_string(" ");
	                  rest.print(); self; } };
};

(*
 * A list of closures we need to build.  We need to number (well, name)
 * the closures uniquely.
 *)
class LambdaList {
  isNil() : Bool { true };
  headE() : VarList { { abort(); new VarList; } };
  headC() : Lambda { { abort(); new Lambda; } };
  headN() : Int { { abort(); 0; } };
  tail()  : LambdaList { { abort(); new LambdaList; } };
  add(e : VarList, x : Lambda, n : Int) : LambdaList {
    (new LambdaListNE).init(e, x, n, self)
  };
};

class LambdaListNE inherits LambdaList {
  lam : Lambda;
  num : Int;
  env : VarList;
  rest : LambdaList;
  isNil() : Bool { false };
  headE() : VarList { env };
  headC() : Lambda { lam };
  headN() : Int { num };
  tail()  : LambdaList { rest };
  init(e : VarList, l : Lambda, n : Int, r : LambdaList) : LambdaListNE {
    {
      env <- e;
      lam <- l;
      num <- n;
      rest <- r;
      self;
    }
  };
};

class LambdaListRef {
  nextNum : Int <- 0;
  l : LambdaList;
  isNil() : Bool { l.isNil() };
  headE() : VarList { l.headE() };
  headC() : Lambda { l.headC() };
  headN() : Int { l.headN() };
  reset() : SELF_TYPE {
    {
      nextNum <- 0;
      l <- new LambdaList;
      self;
    }
  };
  add(env : VarList, c : Lambda) : Int {
    {
      l <- l.add(env, c, nextNum);
      nextNum <- nextNum + 1;
      nextNum - 1;
    }
  };
  removeHead() : SELF_TYPE {
    {
      l <- l.tail();
      self;
    }
  };
};

(*
 * Lambda expressions
 *
 *)

-- A pure virtual class representing any expression
class Expr inherits IO {

  -- Print this lambda term
  print_self() : SELF_TYPE {
    {
      out_string("\nError: Expr is pure virtual; can't print self\n");
      abort();
      self;
    }
  };

  -- Do one step of (outermost) beta reduction to this term
  beta() : Expr {
    {
      out_string("\nError: Expr is pure virtual; can't beta-reduce\n");
      abort();
      self;
    }
  };

  -- Replace all occurrences of x by e
  substitute(x : Variable, e : Expr) : Expr {
    {
      out_string("\nError: Expr is pure virtual; can't substitute\n");
      abort();
      self;
    }
  };

  -- Generate Cool code to evaluate this expression
  gen_code(env : VarList, closures : LambdaListRef) : SELF_TYPE {
    {
      out_string("\nError: Expr is pure virtual; can't gen_code\n");
      abort();
      self;
    }
  };
};

(*
 * Variables
 *)
class Variable inherits Expr {
  name : String;

  init(n:String) : Variable {
    {
      name <- n;
      self;
    }
  };

  print_self() : SELF_TYPE {
    out_string(name)
  };

  beta() : Expr { self };
  
  substitute(x : Variable, e : Expr) : Expr {
    if x = self then e else self fi
  };

  gen_code(env : VarList, closures : LambdaListRef) : SELF_TYPE {
    let cur_env : VarList <- env in
      { while (if cur_env.isNil() then
	          false
	       else
	         not (cur_env.head() = self)
	       fi) loop
	  { out_string("get_parent().");
	    cur_env <- cur_env.tail();
          }
        pool;
        if cur_env.isNil() then
          { out_string("Error:  free occurrence of ");
            print_self();
            out_string("\n");
            abort();
            self;
          }
        else
          out_string("get_x()")
        fi;
      }
  };
};

(*
 * Functions
 *)
class Lambda inherits Expr {
  arg : Variable;
  body : Expr;

  init(a:Variable, b:Expr) : Lambda {
    {
      arg <- a;
      body <- b;
      self;
    }
  };

  print_self() : SELF_TYPE {
    {
		out_string("Lambda\n");
      out_string("");
      arg.print_self();
      out_string(".");
      body.print_self();
      self;
    }
  };

  beta() : Expr { 
	  {
		  out_string("lam beta is called...");
		  self;
		} 
	};

  apply(actual : Expr) : Expr {
	  {
		  out_string("Lambda::apply is called...\n");
    	body.substitute(arg, actual);
	  }
  };

  -- We allow variables to be reused
  substitute(x : Variable, e : Expr) : Expr {
    if x = arg then
      self
    else
      let new_body : Expr <- body.substitute(x, e),
	  new_lam : Lambda <- new Lambda in
	new_lam.init(arg, new_body)
    fi
  };

  gen_code(env : VarList, closures : LambdaListRef) : SELF_TYPE {
    {
      out_string("((new Closure");
      out_int(closures.add(env, self));
      out_string(").init(");
      if env.isNil() then
        out_string("new Closure))")
      else
	out_string("self))") fi;
      self;
    }
  };

  gen_closure_code(n : Int, env : VarList,
		   closures : LambdaListRef) : SELF_TYPE {
    {
      out_string("class Closure");
      out_int(n);
      out_string(" inherits Closure {\n");
      out_string("  apply(y : EvalObject) : EvalObject {\n");
      out_string("    { out_string(\"Applying closure ");
      out_int(n);
      out_string("\\n\");\n");
      out_string("      x <- y;\n");
      body.gen_code(env.add(arg), closures);
      out_string(";}};\n");
      out_string("};\n");
    }
  };
};

(*
 * Applications
 *)
class App inherits Expr {
  fun : Expr;
  arg : Expr;

  init(f : Expr, a : Expr) : App {
    {
		out_string("App init is called!\n");
      fun <- f;
      arg <- a;
      self;
    }
  };

  print_self() : SELF_TYPE {
    {
		out_string("App\n");
      out_string("((");
      fun.print_self();
      out_string(")@(");
      arg.print_self();
      out_string("))");
      self;
    }
  };

  beta() : Expr {
	{
		out_string("App beta is called\n");
		fun.print_self();
		case fun of
		l : Lambda => {
			out_string("\n is type Lambda...\n");
			l.apply(arg);
			-- l.print_self();
		}; 
		e : Expr => {
			out_string("\n is type expression...\n");
			let new_fun : Expr <- fun.beta(),
				new_app : App <- new App in
			new_app.init(new_fun, arg);
		};
		esac;
	}
  };

  substitute(x : Variable, e : Expr) : Expr {
    let new_fun : Expr <- fun.substitute(x, e),
        new_arg : Expr <- arg.substitute(x, e),
        new_app : App <- new App in
      new_app.init(new_fun, new_arg)
  };

  gen_code(env : VarList, closures : LambdaListRef) : SELF_TYPE {
    {
      out_string("(let x : EvalObject <- ");
      fun.gen_code(env, closures);
      out_string(",\n");
      out_string("     y : EvalObject <- ");
      arg.gen_code(env, closures);
      out_string(" in\n");
      out_string("  case x of\n");
      out_string("    c : Closure => c.apply(y);\n");
      out_string("    o : Object => { abort(); new EvalObject; };\n");
      out_string("  esac)");
    }
  };
};

(*
 * Term: A class for building up terms
 *
 *)

class Term inherits IO {
  (*
   * The basics
   *)
  var(x : String) : Variable {
    let v : Variable <- new Variable in
      v.init(x)
  };

  lam(x : Variable, e : Expr) : Lambda {
    let l : Lambda <- new Lambda in
      l.init(x, e)
  };

  app(e1 : Expr, e2 : Expr) : App {
    let a : App <- new App in
      a.init(e1, e2)
  };

  (*
   * Some useful terms
   *)
  i() : Expr {
    let x : Variable <- var("x") in
      lam(x,x)
  };

  k() : Expr {
    let x : Variable <- var("x"),
        y : Variable <- var("y") in
    lam(x,lam(y,x))
  };

  s() : Expr {
    let x : Variable <- var("x"),
        y : Variable <- var("y"),
        z : Variable <- var("z") in
      lam(x,lam(y,lam(z,app(app(x,z),app(y,z)))))
  };

};

class Main inherits Term {
  -- Beta-reduce an expression, printing out the term at each step
  beta_reduce(e : Expr) : Expr {
    {
      out_string("-------------beta-reduce: ");
      e.print_self();
      let done : Bool <- false,
          new_expr : Expr in
        {
	  		while (not done) loop
	    	{
				out_string("before call beta()\n");
	      		new_expr <- e.beta();
				out_string("after call beta()\n");
	      		if (new_expr = e) then
					done <- true
	      		else
				{
		  			e <- new_expr;
		  			-- out_string(" =>\n");
		  			-- e.print_self();
				}
	      		fi;
	    	}
          	pool;
	  		out_string("\n");
          	e;
		};
    }
  };

  main() : Int {
    {
    --   i().print_self();
    --   out_string("\n");
    --   k().print_self();
    --   out_string("\n");
    --   s().print_self();
    --   out_string("\n");
      beta_reduce(app(app(i(), i()), i()));
      0;
    }
  };
};









