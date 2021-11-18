package Ej2;

public class FactoryEspectaculo {
	static String titulo;
	static String descripcion;
	static String categoria;
	static Integer aforo;
	static String fecha;
	static Integer hora;
	static String diaSemana;
	static String fechaInicio;
	static String fechaFin;
	
	public static EspectaculoMultiple getEspectaculoMultiple() {
		return new EspectaculoMultiple(titulo, descripcion, categoria, aforo);
	} 
		
	public static EspectaculoPuntual getEspectaculoPuntual() {
		return new EspectaculoPuntual(titulo, descripcion, categoria, aforo, fecha, hora);
	}	
		
	public static EspectaculoTemporada getEspectaculoTemporada() {
		return new EspectaculoTemporada(titulo, descripcion, categoria, aforo, diaSemana, fechaInicio, fechaFin);
	}	
}
