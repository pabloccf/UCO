package Practica2;
import java.io.*;
import java.util.ArrayList;

public class GestorEspectaculos {
	ArrayList <Espectaculo> listaEspectaculo = new ArrayList<Espectaculo>();
	
	private static GestorEspectaculos instance = null; 
    public static GestorEspectaculos getInstance() { 
        if (instance == null) {
            instance = new GestorEspectaculos();
        }

        return instance;
    }
  private GestorEspectaculos() {
    	leerFichero();
    }
  
  private void leerFichero() {
	  File fich = null;
	  FileReader fr = null;
	  BufferedReader br = null;
	  
	  try {
		  fich = new File("dirección del fichero");
		  fr = new FileReader(fich);
		  br = new BufferedReader(br);
		  
		  String titulo;
		  while ((titulo=br.readLine())!=null) {
			  String descripcion = br.readLine();
			  String categoria = br.readLine();
			  String aforo_str = br.readLine();
			  Integer aforo = Integer.parseInt(aforo_str);
			  String entradas_str = br.readLine();
			  Integer entradas = Integer.parseInt(entradas_str);
			  String localidad = br.readLine();
			  
			  
			  String tipo = br.readLine();
			  if(tipo=="puntual") {
				  String fecha = br.readLine();
				  String hora_str = br.readLine();
				  Integer hora = Integer.parseInt(hora_str);
				  EspectaculoPuntual espectaculo = new EspectaculoPuntual(titulo, descripcion, categoria, aforo, fecha, hora);
				  espectaculo.setEntradasVendidas(entradas);
				  espectaculo.setLocalidad(localidad);
				  listaEspectaculo.add(espectaculo);
			  }
			  
			  else if(tipo=="multiple") {
				  String tiempo_str = br.readLine();
				  Integer tiempo = Integer.parseInt(tiempo_str);
				  
				  ArrayList <timeStamp> lista1 = new ArrayList <timeStamp>();
				  for(int i=0; i<tiempo; i++) {
					  String timeStamp_str = br.readLine();
					  timeStamp timeStamp1 = new timeStamp(timeStamp_str);
					  lista1.add(timeStamp1);
				  }
				  EspectaculoMultiple espectaculo = new EspectaculoMultiple(titulo, descripcion, categoria, aforo);
				  espectaculo.setListaTime(lista1);
				  espectaculo.setEntradasVendidas(entradas);
				  espectaculo.setLocalidad(localidad);
				  listaEspectaculo.add(espectaculo);
			  }
			  
			  else if(tipo=="temporada") {
				  String diaSemana = br.readLine();
				  String fechaInicio = br.readLine();
				  String fechaFin = br.readLine();
				  EspectaculoTemporada espectaculo = new EspectaculoTemporada(titulo, descripcion, categoria, aforo, diaSemana, fechaInicio, fechaFin);
				  espectaculo.setEntradasVendidas(entradas);
				  espectaculo.setLocalidad(localidad);
				  listaEspectaculo.add(espectaculo);
			  }
		  }
	  }
	  catch(Exception e) {
			e.printStackTrace();
		}finally {
			try{
				if(null != fr) {
					fr.close();
				}
			}catch (Exception e2) {
				e2.printStackTrace();
			}
		}
  }
  
 private void escribirFichero() {
	 //Para escribir en el fichero 
	 FileWriter fichero = null;
	 PrintWriter pw = null;
	 ArrayList <timeStamp> listaAux = new ArrayList<timeStamp>();
	 try {
		 fichero = new FileWriter("ruta que hay que poner");
		 pw = new PrintWriter(fichero);
		 
		 for(int i=0; i<this.listaEspectaculo.size(); i++) {
			 if(listaEspectaculo.get(i) instanceof EspectaculoMultiple) {
				 pw.println(listaEspectaculo.get(i).getTitulo());
				 pw.println(listaEspectaculo.get(i).getDescripcion());
				 pw.println(listaEspectaculo.get(i).getCategoria());
				 pw.println(listaEspectaculo.get(i).getAforo());
				 pw.println(listaEspectaculo.get(i).getEntradasVendidas());
				 pw.println(listaEspectaculo.get(i).getLocalidad());
				 
				 listaAux = (((EspectaculoMultiple)(listaEspectaculo.get(i))).getListaTime());//lista para guarda la lista que vamos a obtener timeStamp
				 	for(int j=0; j<listaAux.size();j++) {
				 	    pw.println(listaAux.get(j).toString());
				 	}
				 
				 
			 }
			 
			 else if(listaEspectaculo.get(i) instanceof EspectaculoPuntual) {
				 pw.println(listaEspectaculo.get(i).getTitulo());
				 pw.println(listaEspectaculo.get(i).getDescripcion());
				 pw.println(listaEspectaculo.get(i).getCategoria());
				 pw.println(listaEspectaculo.get(i).getAforo());
				 pw.println(listaEspectaculo.get(i).getEntradasVendidas());
				 pw.println(listaEspectaculo.get(i).getLocalidad());
				 pw.println(((EspectaculoPuntual)(listaEspectaculo.get(i))).getFecha());
				 pw.println(((EspectaculoPuntual)(listaEspectaculo.get(i))).getHora());
			 }
			 
			 else if(listaEspectaculo.get(i) instanceof EspectaculoTemporada) {
				 pw.println(listaEspectaculo.get(i).getTitulo());
				 pw.println(listaEspectaculo.get(i).getDescripcion());
				 pw.println(listaEspectaculo.get(i).getCategoria());
				 pw.println(listaEspectaculo.get(i).getAforo());
				 pw.println(listaEspectaculo.get(i).getEntradasVendidas());
				 pw.println(listaEspectaculo.get(i).getLocalidad());
				 pw.println(((EspectaculoTemporada)(listaEspectaculo.get(i))).getDiaSemana());
				 pw.println(((EspectaculoTemporada)(listaEspectaculo.get(i))).getFechaInicio());
				 pw.println(((EspectaculoTemporada)(listaEspectaculo.get(i))).getFechaFin());					 
			 }
		 }
	 }
	 catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				if(null != fichero)
					fichero.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
 }
  
  public void AltaEspectaculo(Espectaculo espectaculo) {
	  //Almacenamos el espectaculo en una lista y de la lista lo vaciamos en el fichero 
	   listaEspectaculo.add(espectaculo);
	   escribirFichero();   
	  
  }
  
  public void CancelarEspectaculo(Espectaculo espectaculo) {
	  //El usuario le pasa un espectaculo al que no puede asistir, lo elimininamos de la lista de los espectaculo y reescribimos el fichero
	  listaEspectaculo.remove(espectaculo);
	  escribirFichero();
  }
  
  public void ActualizarEspectaculo(Espectaculo espectaculo) {
	  for(int i=0; i<listaEspectaculo.size();i++) {
		  if(listaEspectaculo.get(i).getTitulo().equals(espectaculo.getTitulo())) {
			  listaEspectaculo.remove(i);
			  listaEspectaculo.add(espectaculo);
			  escribirFichero();
		  }
	  }
  }
  
  public void VentaEntradas(String titulo) {
	  for(int i=0; i<listaEspectaculo.size();i++) {
		  if(listaEspectaculo.get(i).getTitulo().equals(titulo)) {
			  listaEspectaculo.get(i).setEntradasVendidas(listaEspectaculo.get(i).getEntradasVendidas()+1) ;
		  }
	  }
  }
  
  public ArrayList<Espectaculo> LocalidadesDisponibles(String fecha) {
	 //En esta hay problemas 
	  ArrayList<Espectaculo> result = new ArrayList<Espectaculo>();
	  for (int i = 0; i < listaEspectaculo.size(); i++) {
		  Espectaculo e = listaEspectaculo.get(i);

		  if (e instanceof EspectaculoPuntual && ((EspectaculoPuntual)e).getFecha().equals(fecha)) {
			  result.add(e);
		  }
		  else if (e instanceof EspectaculoMultiple) {
			  EspectaculoMultiple em = (EspectaculoMultiple)e;
			  for (int j = 0; j < em.getListaTime().size(); j++) {
				  if (em.getListaTime().get(j).getFecha().equals(fecha)) {
					  result.add(e);
				  }
			  }
		  }
		  else {
			  EspectaculoTemporada et = (EspectaculoTemporada)e;
			  String fechaInicio = et.getFechaInicio();
			  String fechaFin = et.getFechaFin();

				//Asumimos que se usa el formato DD/MM/AAAA
				String[] fechaParts = fecha.split("/");
				String[] inicioParts = fechaInicio.split("/");
				String[] finParts = fechaFin.split("/");

				int fechaDia = Integer.parseInt(fechaParts[0]);
				int fechaMes = Integer.parseInt(fechaParts[1]);
				int fechaYear = Integer.parseInt(fechaParts[2]);

				int inicioDia = Integer.parseInt(inicioParts[0]);
				int inicioMes = Integer.parseInt(inicioParts[1]);
				int inicioYear = Integer.parseInt(inicioParts[2]);

				int finDia = Integer.parseInt(finParts[0]);
				int finMes = Integer.parseInt(finParts[1]);
				int finYear = Integer.parseInt(finParts[2]);

			  if (fechaYear < finYear && fechaYear > inicioYear) {
				  if (fechaMes < finMes && fechaMes > inicioMes) {
					  if (fechaDia < finDia && fechaDia > inicioDia) {
						  result.add(e);
					  }
				  }
			  }
		  }
	  }

	  return result;
  }
  
  public Espectaculo BusquedaEspectaculosTitulo(String titulo) {
	  Espectaculo espectaculo = null;
	  for(int i=0; i<listaEspectaculo.size();i++) {
		  if(listaEspectaculo.get(i).getTitulo().equals(titulo)) {
			  espectaculo = listaEspectaculo.get(i);
		  }
	  }
	  return espectaculo;
  }
  
  public ArrayList<Espectaculo> BusquedaEspectaculosCategoria(String categoria) {
	  ArrayList <Espectaculo> listilla = new ArrayList<Espectaculo>();
	  
	  for(int i=0; i<listaEspectaculo.size();i++) {
		  if(listaEspectaculo.get(i).getCategoria().equals(categoria)) {
			  listilla.add(listaEspectaculo.get(i));
		  }
	  }
	  return listilla;
  }
  
}
