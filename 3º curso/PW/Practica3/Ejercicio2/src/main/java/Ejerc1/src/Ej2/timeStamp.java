package Ejerc1.src.Ej2;

/**
 * Esta clase es la que se encarga de la fecha
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
public class timeStamp {
	private String hora;
	private String fecha;
	
	/**
	 * Constructor de la fecha
	 * @param hora Es la hora 
	 * @param fecha Se refiere al día, mes y año
	 */
	public timeStamp(String hora, String fecha) {
		super();
		this.hora = hora;
		this.fecha = fecha;
	}

	/**
	 * Método que devuelve la hora
	 * @return La hora
	 */
	public String getHora() {
		return hora;
	}

	/**
	 * Método que establece un valor a la hora
	 * @param hora La hora que el usuario introduce por pantalla
	 */
	public void setHora(String hora) {
		this.hora = hora;
	}

	/**
	 * Método que devuelve la fecha
	 * @return La fecha
	 */
	public String getFecha() {
		return fecha;
	}

	/**
	 * Método que establece un valor a la fecha
	 * @param fecha La fecha que el usuario introduce por pantalla
	 */
	public void setFecha(String fecha) {
		this.fecha = fecha;
	}
	
	public String toString() {
		return hora+";"+fecha;
	}

	public timeStamp(String timeStamp) {
		String[] array = timeStamp.split(";");
		this.hora = array[0];
		this.fecha = array[1];
	}
}