function placing ()
  print(nbPalcePerso())
  placePerso(7,2,1);
end


function main ()
  -- life = getLifePerso( getCoodPerso() )
  -- life = getLifePerso( 1,6  )
  -- print(getCoodPerso())
  print(getNearestEnemy( getCoodPerso() ))
  print(getCellContent( 4,0 ))
  x,y =getCoodPerso()
  -- content = getCellContent( 11,0 )
  -- print(content)
  print(getPathLength( x,y , 9,0 ))
end
