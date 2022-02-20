package Ejerc1.src.Ej2;

/**
 * Esta clase contiene el constructor, los get y los set de los espectaculos.
 * @author Pablo López Gosálvez, Pablo Ibañez Fernández-Delgado y José Ángel Dorado González
 * @version openjdk version 11.0.12 2021-07-20
 */

public class EspectaculoDTO {
	private String titulo;
	private String descripcion;
	private String categoria;
	private Integer aforo;
	private Integer entradasVendidas;
	private String localidad;
	private String fecha;
	private String tipo;
	private Integer numeroEspectaculos;
	private String hora;
	private String fechaFin;
	private String horaFin;
	private Integer dia;
	private int id;

	
	/**
	 * Constructor de los datos de los espectáculos
	 * @param titulo Es el título del espectáculo
	 * @param descripcion Es la descripción del espectáculo
	 * @param categoria Es la categoría del espectáculo
	 * @param aforo Es el aforo del espectáculo
	 */
	public EspectaculoDTO(String titulo, String descripcion, String categoria, Integer aforo, int id) {
		super();
		this.titulo = titulo;
		this.descripcion = descripcion;
		this.categoria = categoria;
		this.aforo = aforo;
		this.entradasVendidas = 0;
		this.localidad = "";
		this.id = id;
	}

	/**
	 * Constructor de los datos de los espectáculos
	 * @param titulo Es el título del espectáculo
	 * @param descripcion Es la descripción del espectáculo
	 * @param categoria Es la categoría del espectáculo
	 * @param aforo Es el aforo del espectáculo
	 * @param entradasVendidas Son las entradas vendidas de los espectáculos
	 * @param fecha Es la fecha del espectáculo
	 */
	public EspectaculoDTO(String titulo, String descripcion, String categoria, Integer aforo, Integer entradasVendidas, String fecha, String tipo, int numeroEspectaculos, String hora, String fechaFin, String horaFin, int dia, int id) {
		super();
		this.titulo = titulo;
		this.descripcion = descripcion;
		this.categoria = categoria;
		this.aforo = aforo;
		this.entradasVendidas = entradasVendidas;
		this.localidad = "";
		this.fecha = "";
		this.tipo = "";
		this.numeroEspectaculos = numeroEspectaculos;
		this.hora = "";
		this.fechaFin = "";
		this.horaFin = "";
		this.dia = dia;
		this.id = id;

	}

	/**
	 * Constructor vacío de los datos de los espectáculos
	 */
	public EspectaculoDTO() {
		this.titulo = "";
		this.descripcion = "";
		this.categoria = "";
		this.aforo = 0;
		this.entradasVendidas = 0;
		this.localidad = "";
		this.fecha = "";
		this.tipo = "";
		this.numeroEspectaculos=0;
		this.hora = "";
		this.fechaFin = "";
		this.horaFin = "";
		this.dia = 0;
		this.id = -1;

	}

	/**
	 * Método que devuelve el título del espectáculo
	 * @return El título del espectáculo
	 */
	public String getTitulo() {
		return titulo;
	}

	/**
	 * Método que establece un valor al título del espectáculo
	 * @param titulo Es el título del espectáculo que el usuario introduce por pantalla
	 */
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	/**
	 * Método que devuelve la descripción sobre el espectáculo
	 * @return La descripción sobre el espectáculo
	 */
	public String getDescripcion() {
		return descripcion;
	}

	/**
	 * Método que establece un valor a la descripción del espectáculo
	 * @param texto Es la descripción del espectáculo que el usuario introduce por pantalla
	 */
	public void setDescripcion(String descripcion) {
		this.descripcion = descripcion;
	}

	/**
	 * Método que devuelve la categoría del espectáculo
	 * @return La categoría del espectáculo
	 */
	public String getCategoria() {
		return categoria;
	}

	/**
	 * Método que establece un valor a la categoría del espectáculo
	 * @param categoria Es la categoría del espectáculo que el usuario introduce por pantalla
	 */
	public void setCategoria(String categoria) {
		this.categoria = categoria;
	}

	/**
	 * Método que devuelve el aforo del espectáculo
	 * @return El aforo del espectáculo
	 */
	public Integer getAforo() {
		return aforo;
	}

	/**
	 * Método que establece un valor al aforo del espectáculo
	 * @param aforo Es el aforo del espectáculo que el usuario introduce por pantalla
	 */
	public void setAforo(Integer aforo) {
		this.aforo = aforo;
	}
		
	/**
	 * Método que devuelve el número de entradas vendidas del espectáculo
	 * @return El número de entradas vendidas del espectáculo
	 */
	public Integer getEntradasVendidas() {
		return entradasVendidas;
	}

	/**
	 * Método que establece un valor al número de entradas vendidas del espectáculo
	 * @param entradasVendidas Es el número de entradas vendidas del espectáculo que el usuario introduce por pantalla
	 */
	public void setEntradasVendidas(Integer entradasVendidas) {
		this.entradasVendidas = entradasVendidas;
	}
		
	/**
	 * Método que devuelve la localidad del espectáculo
	 * @return La localidad del espectáculo
	 */
	public String getLocalidad() {
		return localidad;
	}

	/**
	 * Método que establece un valor a la localidad del espectáculo
	 * @param localidad Es la localidad del espectáculo
	 */
	public void setLocalidad(String localidad) {
		this.localidad = localidad;
	}

	/**
	 * Método que devuelve la fecha del espectáculo
	 * @return La fecha del espectáculo
	 */
	public String getFecha() {
		return fecha;
	}

	/**
	 * Método que establece un valor a la fecha del espectáculo
	 * @param fecha Es la fecha del espectáculo que el usuario introduce por pantalla
	 */
	public void setFecha(String fecha) {
		this.fecha = fecha;
	}	
	
	/**
	 * Método que devuelve el tipo del espectáculo
	 * @return El tipo del espectáculo
	 */
	public String getTipo() {
		return tipo;
	}

	/**
	 * Método que establece un valor al tipo de espectáculo
	 * @param tipo Es el tipo de espectáculo que el usuario introduce por pantalla
	 */
	public void setTipo(String tipo) {
		this.tipo = tipo;
	}	
	
	/**
	 * Método que devuelve el numero de espectaculos del tipo de espectaculo
	 * @return Numero de espectaculo del espectaculo
	 */
	public int getEspectaculos() {
		return numeroEspectaculos;
	}

	/**
	 * Método que establece un valor al numero de espectáculos
	 * @param numeroEspectaculos Es el numero de espectáculos que el usuario introduce por pantalla
	 */
	public void setEspectaculos(int numeroEspectaculos) {
		this.numeroEspectaculos = numeroEspectaculos;
	}
	
	/**
	 * Método que devuelve la hora de inicio del espectáculo
	 * @return La hora de inicio del espectáculo
	 */
	public String getHora() {
		return hora;
	}

	/**
	 * Método que establece un valor a la hora de inicio de espectáculo
	 * @param hora Es la hora de inicio del espectáculo que el usuario introduce por pantalla
	 */
	public void setHora(String hora) {
		this.hora = hora;
	}	
	
	/**
	 * Método que devuelve la fecha de fin del espectáculo
	 * @return La fecha de fin del espectáculo
	 */
	public String getFechaFin() {
		return fechaFin;
	}

	/**
	 * Método que establece un valor a la fecha de fin de espectáculo
	 * @param fechaFin Es la fecha de fin del espectáculo que el usuario introduce por pantalla
	 */
	public void setFechaFin(String fechaFin) {
		this.fechaFin = fechaFin;
	}	
	
	/**
	 * Método que devuelve la hora de fin del espectáculo
	 * @return La hora de fin del espectáculo
	 */
	public String getHoraFin() {
		return horaFin;
	}

	/**
	 * Método que establece un valor a la hora de fin de espectáculo
	 * @param horaFin Es la hora de fin del espectáculo que el usuario introduce por pantalla
	 */
	public void setHoraFin(String horaFin) {
		this.horaFin = horaFin;
	}	
	
	/**
	 * Método que devuelve el dia de la semana del espectaculo
	 * @return El dia de la semana del espectaculo
	 */
	public int getDia() {
		return dia;
	}

	/**
	 * Método que establece un valor al dia de la semana en el que se celebra el espectaculo
	 * @param dia Es el dia de la semana del espectáculo que el usuario introduce por pantalla
	 */
	public void setDia(int dia) {
		this.dia = dia;
	}	
	
	/**
	 * Método que devuelve la id de la critica
	 * @return La id de la critica
	 */
	public int getID() {
		return id;
	}

	/**
	 * Método que establece un valor a la id de la critica
	 * @param id Identificador de la critica
	 */
	public void setID(int id) {
		this.id = id;
	}
}