
#include <iostream>
#include <set> 
#include "scrabble.hpp"




ScrabbleSolver::ScrabbleSolver(){

}

void ScrabbleSolver::add_word( std::string const& word ){
    if(dictionary.contains(word)){
    throw std::runtime_error("already present");
}
  else{
       dictionary.insert(word);
      
  }
    
}



ScoreMap ScrabbleSolver::get_score_map(){
ScoreMap mapped;
for(auto x : dictionary){
    mapped[x]=compute_score(x);
}
  return mapped;  
}

ScoreMap ScrabbleSolver::find_words( TileSet const& tiles ){
  
    ScoreMap result;
    ScoreMap reference_map = get_score_map();

    for (const auto& wor: dictionary) {
        if (can_make_word(wor, tiles)) {
            int score = reference_map[wor];
            result[wor] = score;
        }
    }

    return result;
}



    
    


ScoreMap ScrabbleSolver::find_best_words( TileSet const& tiles ){

}




int ScrabbleSolver::compute_score( std::string const& word ){
std::map<char,int> table;
    table['a'] = table['e'] = table['i'] = table['l'] = table['n'] =table['o'] = table['r'] = table['s'] = table['t'] = table['u'] = 1;
    table['d'] = table['g'] = 2;
    table['b'] = table['c'] = table['m'] = table['p'] = 3;
    table['f'] = table['h'] = table['v'] = table['w'] = table['y'] = 4;
    table['k'] = 5;
    table['j'] = table['x'] = 8;
    table['q'] = table['z'] = 10;
    int sum = 0;
    for ( auto x : word){
        sum = sum + table[x];
    }
    return sum ;
        
}


bool ScrabbleSolver::can_make_word( std::string const& word, TileSet const& tiles ){
    TileSet copy = tiles ; 
 for(auto x : word) {
     
    auto iter = copy.find(x);
        if(iter != copy.end()){
            copy.erase(iter);
            
        }
     else 
         return false ; 
 }
    return true;
   
}

