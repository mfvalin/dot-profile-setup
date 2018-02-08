#!/bin/bash
export SSMDOMAINHOME=${0%/all/bin/*}
if [[ -r ${SSMDOMAINHOME:-i_en_a_pas}/etc/ssm.d/profile ]]
then
  . $SSMDOMAINHOME/etc/ssm.d/profile  1>&2
  echo USING SSMDOMAINHOME=$(true_path ${SSMDOMAINHOME})  1>&2
else
  . /etc/profile  1>&2
  . ./.profile  1>&2
fi
#export SSMDOMAINHOME=`true_path $SSMDOMAINHOME`
eval "$@"
#if [[ -r $HOME/ECssm/etc/ssm.d/profile ]]
#then
#  export SSMDOMAINHOME=${HOME}/ECssm 
#  . $SSMDOMAINHOME/etc/ssm.d/profile 
#else
#  if [[ -r $HOME/EC_export_ssm/etc/ssm.d/profile ]]
#  then
#    export SSMDOMAINHOME=${HOME}/EC_export_ssm 
#    . $SSMDOMAINHOME/etc/ssm.d/profile 
#  fi
#fi
#echo USING SSMDOMAINHOME=${SSMDOMAINHOME}
#eval "$@"
