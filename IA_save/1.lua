function placing ()
  if nbPlacePerso()%2 == 0 then
    placePerso(2,2,1)
  else
    placePerso(8,2,1)
  end
end

function main ()
  i , j = getNearestEnemy()
  useWeaponOnCell("Tir à l'arc",i,j)
  moveToward( i , j , 3)
  useWeaponOnCell("Tir à l'arc",i,j)
end
