# BiciPlusPlus 
### Autore - [Simone Cisca](https://github.com/SpaceCowboySCX)

## Progetto per migliorare la sicurezza in bici
### Introduzione
Quando si viaggia su due ruote, c'è una regola fondamentale: indipendentemente da chi abbia ragione o torto, è il
ciclista a rischiare di più.
<br>
A differenza delle auto, le biciclette non dispongono di sistemi di sicurezza attiva che possano prevenire gli incidenti.
L'unica vera protezione è la prevenzione, ovvero evitare situazioni di pericolo.
<br>
Anche con la massima attenzione, è fondamentale segnalare chiaramente la propria presenza e intenzioni agli altri utenti della
strada. Per migliorare la visibilità e la comunicazione del ciclista, questo progetto introduce un sistema di indicatori
di direzione e luci di stop utilizzando Arduino.

### Obiettivi
L'obiettivo principale del progetto è aumentare la sicurezza del ciclista in strada.
<br>
Per raggiungere questo obiettivo, il progetto si propone di:
<br>
- **Migliorare la visibilità del ciclista**: grazie a indicatori di direzione e luci di stop, il ciclista sarà più
  visibile.
- **Migliorare la comunicazione del ciclista**: grazie agli indicatori di direzione, il ciclista potrà segnalare
  chiaramente
  le proprie intenzioni agli altri utenti della strada.

### Componenti
Il progetto è composto da:
- [Arduino Uno](./Documentation/ArduinoUno): il cuore del sistema, che controlla le luci e i sensori.
- [Luci](./Documentation/WS2812B): luci a LED per segnalare le intenzioni del ciclista.
- [Alimentazione](./Documentation/PowerSupply): batterie per alimentare il sistema.
- [Interfaccia utente](./Documentation/UserInterfaceElements): pulsanti per attivare gli indicatori di direzione.
- [Custodia](./Documentation/CoverCase): contenitore per proteggere il sistema.
- Sensori: sensori per rilevare le azioni del ciclista.

#### [Arduino Uno](./Documentation/ArduinoUno)
L'Arduino Uno è ideale per questo progetto grazie alla sua semplicità d'uso, alla vasta documentazione disponibile e
al numero adeguato di porte di input/output necessarie per gestire i LED e gli switch. Inoltre, è facilmente
programmabile tramite l'IDE Arduino e ha un ampio supporto nella community, il che facilita la risoluzione di
eventuali problemi.
Alternative:
Arduino Nano - potrebbe essere un'alternativa più compatta, ma ha un numero minore di pin accessibili.
ESP8266 - offre capacità Wi-Fi aggiuntive, ma potrebbe essere sovradimensionato per un progetto semplice
come questo.

#### [Luci WS2812B](./Documentation/WS2812B)
La striscia LED WS2812B è una scelta eccellente per la sua capacità di controllare singolarmente ogni LED tramite
un singolo pin dell'Arduino, riducendo il numero di connessioni necessarie. Questa flessibilità è particolarmente
utile
per segnalare direzioni o frenate, accendendo solo alcuni LED a seconda della necessità.
Alternative:
Neopixel - sono simili ai WS2812B ma tendono a essere più costosi
LED RGB tradizionali - richiederebbero un numero maggiore di pin di controllo, rendendo il circuito più complesso.
  
#### [Alimentazione](./Documentation/PowerSupply)
L'uso di un Power Bank garantisce un'alimentazione portatile e facilmente ricaricabile, perfetta per un progetto di
bici.
Con una capacità sufficiente, il power bank può alimentare sia l'Arduino che la striscia LED per un lungo periodo
senza la necessità di essere frequentemente ricaricato.
Alternative:
Batteria LiPo - più leggere e potenti, ma richiedono un circuito di ricarica specifico
Batteria 9V - meno duratura e richiede sostituzioni frequenti.

#### [Interfaccia utente](./Documentation/UserInterfaceElements)
Per semplificare l'interfaccia utente, si può utilizzare uno switch a scorrimento a tre posizione per selezionare la
direzione di svolta. Questo permette al ciclista di segnalare la propria intenzione senza dover premere un pulsante
continuamente o avere troppi interruttori separati.
Un ulteriore pulsante può essere utilizzato per attivare le luci frontali per illuminare la strada.
Alternative:
Pulsanti a pressione - richiedono una pressione continua per rimanere attivi.

#### [Custodia](./Documentation/CoverCase)
Una custodia impermeabile è essenziale per proteggere l'Arduino e i componenti elettronici dall'acqua e dalla polvere.
Inoltre, una custodia robusta può proteggere il sistema da urti e cadute.
Per praticità e sicurezza, la custodia dovrebbe essere facilmente montabile sulla bici e rimovibile.
Si consiglia di utilizzare una custodia stampata in 3D per adattarsi perfettamente al sistema e alla bici.

#### Sensori
Per rilevare le azioni del ciclista, si possono utilizzare diversi sensori:
- **Switch**: Per attivare la luce rossa di STOP quando il ciclista frena.
  Un semplice switch a pressione può essere montato sul freno per rilevare quando il ciclista sta frenando e
  attivare
  le luci di stop.
  La posizione dello switch sarà a discrezione di chi applicherà il sistema alla propria bici, ma è consigliabile
  posizionarlo in modo che si attivi quando il freno è leggermente premuto, in modo da dare un avviso precoce agli
  altri utenti della strada. Un'idea potrebbe essere montare lo switch sul manubrio, in modo che si attivi quando la
  leva del freno viene premuta, oppure
  sul freno stesso, in modo che si attivi quando il freno viene premuto.
  Quest'ultima soluzione dipende dal tipo di freno e dalla bici.
  Alternative:
  Accelerometro - per rilevare la decelerazione e attivare le luci di stop.
- **Sensore di luce**: per attivare automaticamente le luci quando è buio.
  Un sensore di luce può essere utilizzato per attivare automaticamente le luci quando è buio, garantendo che il
  ciclista sia sempre visibile anche di notte.
  Il sensore di luce può essere montato in un punto ben illuminato della bici, in modo da garantire che le luci
  si attivino solo quando necessario.
  Alternative:
  Pulsante di accensione - per attivare manualmente le luci.

### Architettura

### Riferimenti

### [Licenza](./LICENSE)