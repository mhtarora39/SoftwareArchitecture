#### Component  

Small building block of Architecture

## Types Of Architecture 

1. **Layer Architecture**

<img src="./Layerd%20Architecture.jpg" width="50%" style="vertical-align:middle;margin:50px 5%">


* Build out of layer ( i.e Tcp IP)<br>
  a. **Layer is closed (issue)** ( We can't send or access layer directly )</br>
  b. Layer of isolation (Each layer is component and binded each other by interface)    
  c. No effect on any other layer if any underlying layer change
  d. Separation of concerns.
  e. Architect decide which layer needs to open
  f. Open layer introduce cross layer concerns

### Layer Architecture Concerns

* Good General Architecture 
* Sink Hole : Which out for architecture sinkhole anti-pattern.
* Tends to land at monolithic.

### Analysis 

 1. Overall Agility ( Low ) : Overall design
 2. Deployment ( Low ) : Full deployment is re
 3. Testability ( Good )
 4. Performance ( Low )
 5. Scalability ( Low )
 6. Development ( Good )
 9. Complexity  ( Good )
10. Loose Coupling ( Low )



