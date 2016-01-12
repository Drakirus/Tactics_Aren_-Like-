function placing ()
  if nbPlacePerso()%2 == 0 then
    placePerso(2,2,1)
  else
    placePerso(8,2,1)
  end
end

function main ()
  i , j = getNearestEnemy()
  useWeaponOnCell("Tir a l'arc",i,j)
  moveAway( i , j , 2)
  useWeaponOnCell("Tir a l'arc",i,j)
end
