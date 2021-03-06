
      SUBROUTINE UGINIT                                                         
*                                                                               
*     To initialise GEANT/USER  program and read data cards                     
*
#include "calor.inc"
#include "celoss.inc"                                                                                  
*
      CHARACTER*20 filnam                                                                                                                                                                                                      
*                                                                               
* *** Define the GEANT parameters                                                          
      CALL GINIT 
                                                                          
* *** read data cards
      PRINT *, 'G3 > gives the filename of the data cards to be read:'
      READ (*,'(A)') filnam
      IF (filnam.EQ.' ') filnam = 'testem1.dat'
      OPEN (unit=5,file=filnam,status='unknown',form='formatted')
                                              
*
* *** Calor definition                                               
      CALL FFKEY('CALOR',Imat,3,'MIXED')
*                                                                    
* *** read data cards                                                           
      CALL GFFGO 
                                                                     
*                                                                               
      CALL GZINIT                                                               
      CALL GPART 
*
      CALL GDINIT                                                                     
*                                                                               
* *** Geometry and materials description                                        
      CALL UGEOM                                                                
*                                                                               
* *** Energy loss and cross-sections initialisations                            
      CALL GPHYSI                                                               
*                                                                               
      CALL GPRINT('MATE',0)                                                     
      CALL GPRINT('TMED',0)                                                     
      CALL GPRINT('VOLU',0)                                                     
*                                                                                                                                                              
* *** Define user histograms                                                    
      CALL UHINIT
*
* *** some initialisation
      NTRAK0 = 0
      NTRAK1 = 0
      NSTEP0 = 0
      NSTEP1 = 0
      CALL VZERO (NBCALL,12)                                                               
*                                                                               
      END                                                                       
