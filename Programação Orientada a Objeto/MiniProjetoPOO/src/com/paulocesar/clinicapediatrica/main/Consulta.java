package com.paulocesar.clinicapediatrica.main;

public class Consulta {
	
	private boolean isActive = true;
	private String motivo;
	private String tratamento;
	private String receitaRemedios;
	private String medicoRequisitado;
	
	Consulta(String motivo, String medicoRequisitado){
		setMotivo(motivo);
		setMedicoRequisitado(medicoRequisitado);
	}
	
	public String getTratamento() {
		return tratamento;
	}

	public void setTratamento(String tratamento) {
		this.tratamento = tratamento;
	}

	public String getReceitaRemedios() {
		return receitaRemedios;
	}

	public void setReceitaRemedios(String receitaRemedios) {
		this.receitaRemedios = receitaRemedios;
	}

	public String getMotivo() {
		return motivo;
	}

	public void setMotivo(String motivo) {
		if (motivo.length() > 10)
			this.motivo = motivo;
	}
	
	public String getMedicoRequisitado() {
		return medicoRequisitado;
	}

	public void setMedicoRequisitado(String medicoRequisitado) {
		this.medicoRequisitado = medicoRequisitado;
	}

	public boolean isActive() {
		return isActive;
	}
	
	public void finalizarConsulta() {
		this.isActive = false;
	}
	
}
